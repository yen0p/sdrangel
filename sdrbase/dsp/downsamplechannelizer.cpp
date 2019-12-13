///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2016-2019 F4EXB                                                 //
// written by Edouard Griffiths                                                  //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#include <QString>
#include <QDebug>

#include "dsp/inthalfbandfilter.h"
#include "dsp/dspcommands.h"
#include "dsp/hbfilterchainconverter.h"
#include "downsamplechannelizer.h"

DownSampleChannelizer::DownSampleChannelizer(ChannelSampleSink* sampleSink) :
    m_filterChainSetMode(false),
	m_sampleSink(sampleSink),
	m_basebandSampleRate(0),
	m_requestedOutputSampleRate(0),
	m_requestedCenterFrequency(0),
    m_channelSampleRate(0),
	m_channelFrequencyOffset(0),
    m_log2Decim(0),
    m_filterChainHash(0)
{
}

DownSampleChannelizer::~DownSampleChannelizer()
{
	freeFilterChain();
}

void DownSampleChannelizer::feed(const SampleVector::const_iterator& begin, const SampleVector::const_iterator& end)
{
	if (m_sampleSink == 0)
    {
		m_sampleBuffer.clear();
		return;
	}

	if (m_filterStages.size() == 0) // optimization when no downsampling is done anyway
	{
		m_sampleSink->feed(begin, end);
	}
	else
	{
		for (SampleVector::const_iterator sample = begin; sample != end; ++sample)
		{
			Sample s(*sample);
			FilterStages::iterator stage = m_filterStages.begin();

			for (; stage != m_filterStages.end(); ++stage)
			{
#ifndef SDR_RX_SAMPLE_24BIT
                s.m_real /= 2; // avoid saturation on 16 bit samples
                s.m_imag /= 2;
#endif
				if (!(*stage)->work(&s)) {
					break;
				}
			}

			if(stage == m_filterStages.end())
			{
#ifdef SDR_RX_SAMPLE_24BIT
			    s.m_real /= (1<<(m_filterStages.size())); // on 32 bit samples there is enough headroom to just divide the final result
			    s.m_imag /= (1<<(m_filterStages.size()));
#endif
				m_sampleBuffer.push_back(s);
			}
		}

		m_sampleSink->feed(m_sampleBuffer.begin(), m_sampleBuffer.end());
		m_sampleBuffer.clear();
	}
}

void DownSampleChannelizer::setChannelization(int requestedSampleRate, qint64 requestedCenterFrequency)
{
    m_requestedOutputSampleRate = requestedSampleRate;
    m_requestedCenterFrequency = requestedCenterFrequency;
    applyChannelization();
}

void DownSampleChannelizer::setBasebandSampleRate(int basebandSampleRate, bool decim)
{
    m_basebandSampleRate = basebandSampleRate;

    if (decim) {
        applyDecimation();
    } else {
        applyChannelization();
    }
}

void DownSampleChannelizer::applyChannelization()
{
    m_filterChainSetMode = false;

	if (m_basebandSampleRate == 0)
	{
		qDebug() << "DownSampleChannelizer::applyChannelization: aborting (in=0)"
            << " in (baseband):" << m_basebandSampleRate
            << " req:" << m_requestedOutputSampleRate
            << " out (channel):" << m_channelSampleRate
            << " fc:" << m_channelFrequencyOffset;
        return;
	}

	freeFilterChain();

	m_channelFrequencyOffset = createFilterChain(
		m_basebandSampleRate / -2, m_basebandSampleRate / 2,
		m_requestedCenterFrequency - m_requestedOutputSampleRate / 2, m_requestedCenterFrequency + m_requestedOutputSampleRate / 2);

	m_channelSampleRate = m_basebandSampleRate / (1 << m_filterStages.size());

	qDebug() << "DownSampleChannelizer::applyChannelization done:"
        << " in (baseband):" << m_basebandSampleRate
		<< " req:" << m_requestedOutputSampleRate
		<< " out (channel):" << m_channelSampleRate
		<< " fc:" << m_channelFrequencyOffset;
}

void DownSampleChannelizer::setDecimation(unsigned int log2Decim, unsigned int filterChainHash)
{
    m_log2Decim = log2Decim;
    m_filterChainHash = filterChainHash;
    applyDecimation();
}

void DownSampleChannelizer::applyDecimation()
{
    m_filterChainSetMode = true;
    std::vector<unsigned int> stageIndexes;
    m_channelFrequencyOffset = m_basebandSampleRate * HBFilterChainConverter::convertToIndexes(m_log2Decim, m_filterChainHash, stageIndexes);
    m_requestedCenterFrequency = m_channelFrequencyOffset;

    freeFilterChain();

    m_channelFrequencyOffset = m_basebandSampleRate * setFilterChain(stageIndexes);
    m_channelSampleRate = m_basebandSampleRate / (1 << m_filterStages.size());
    m_requestedOutputSampleRate = m_channelSampleRate;

	qDebug() << "UpChannelizer::applyInterpolation:"
            << " m_log2Interp:" << m_log2Decim
            << " m_filterChainHash:" << m_filterChainHash
            << " out:" << m_basebandSampleRate
			<< " in:" << m_channelSampleRate
			<< " fc:" << m_channelFrequencyOffset;
}

#ifdef SDR_RX_SAMPLE_24BIT
DownSampleChannelizer::FilterStage::FilterStage(Mode mode) :
    m_filter(new IntHalfbandFilterEO<qint64, qint64, DOWNCHANNELIZER_HB_FILTER_ORDER>),
    m_workFunction(0),
    m_mode(mode),
    m_sse(true)
{
    switch(mode) {
        case ModeCenter:
            m_workFunction = &IntHalfbandFilterEO<qint64, qint64, DOWNCHANNELIZER_HB_FILTER_ORDER>::workDecimateCenter;
            break;

        case ModeLowerHalf:
            m_workFunction = &IntHalfbandFilterEO<qint64, qint64, DOWNCHANNELIZER_HB_FILTER_ORDER>::workDecimateLowerHalf;
            break;

        case ModeUpperHalf:
            m_workFunction = &IntHalfbandFilterEO<qint64, qint64, DOWNCHANNELIZER_HB_FILTER_ORDER>::workDecimateUpperHalf;
            break;
    }
}
#else
DownSampleChannelizer::FilterStage::FilterStage(Mode mode) :
    m_filter(new IntHalfbandFilterEO<qint32, qint32, DOWNCHANNELIZER_HB_FILTER_ORDER>),
    m_workFunction(0),
    m_mode(mode),
    m_sse(true)
{
    switch(mode) {
        case ModeCenter:
            m_workFunction = &IntHalfbandFilterEO<qint32, qint32, DOWNCHANNELIZER_HB_FILTER_ORDER>::workDecimateCenter;
            break;

        case ModeLowerHalf:
            m_workFunction = &IntHalfbandFilterEO<qint32, qint32, DOWNCHANNELIZER_HB_FILTER_ORDER>::workDecimateLowerHalf;
            break;

        case ModeUpperHalf:
            m_workFunction = &IntHalfbandFilterEO<qint32, qint32, DOWNCHANNELIZER_HB_FILTER_ORDER>::workDecimateUpperHalf;
            break;
    }
}
#endif

DownSampleChannelizer::FilterStage::~FilterStage()
{
	delete m_filter;
}

bool DownSampleChannelizer::signalContainsChannel(Real sigStart, Real sigEnd, Real chanStart, Real chanEnd) const
{
	//qDebug("   testing signal [%f, %f], channel [%f, %f]", sigStart, sigEnd, chanStart, chanEnd);
	if(sigEnd <= sigStart)
		return false;
	if(chanEnd <= chanStart)
		return false;
	return (sigStart <= chanStart) && (sigEnd >= chanEnd);
}

Real DownSampleChannelizer::createFilterChain(Real sigStart, Real sigEnd, Real chanStart, Real chanEnd)
{
	Real sigBw = sigEnd - sigStart;
	Real rot = sigBw / 4;

	//qDebug("DownSampleChannelizer::createFilterChain: Signal [%.1f, %.1f] (BW %.1f), Channel [%.1f, %.1f], Rot %.1f", sigStart, sigEnd, sigBw, chanStart, chanEnd, rot);

	// check if it fits into the left half
	if(signalContainsChannel(sigStart, sigStart + sigBw / 2.0, chanStart, chanEnd))
    {
		//qDebug("DownSampleChannelizer::createFilterChain: -> take left half (rotate by +1/4 and decimate by 2)");
		m_filterStages.push_back(new FilterStage(FilterStage::ModeLowerHalf));
		return createFilterChain(sigStart, sigStart + sigBw / 2.0, chanStart, chanEnd);
	}

	// check if it fits into the right half
	if(signalContainsChannel(sigEnd - sigBw / 2.0f, sigEnd, chanStart, chanEnd))
    {
		//qDebug("DownSampleChannelizer::createFilterChain: -> take right half (rotate by -1/4 and decimate by 2)");
		m_filterStages.push_back(new FilterStage(FilterStage::ModeUpperHalf));
		return createFilterChain(sigEnd - sigBw / 2.0f, sigEnd, chanStart, chanEnd);
	}

	// check if it fits into the center
	if(signalContainsChannel(sigStart + rot, sigEnd - rot, chanStart, chanEnd))
    {
		//qDebug("DownSampleChannelizer::createFilterChain: -> take center half (decimate by 2)");
		m_filterStages.push_back(new FilterStage(FilterStage::ModeCenter));
		return createFilterChain(sigStart + rot, sigEnd - rot, chanStart, chanEnd);
	}

	Real ofs = ((chanEnd - chanStart) / 2.0 + chanStart) - ((sigEnd - sigStart) / 2.0 + sigStart);
	//qDebug("DownSampleChannelizer::createFilterChain: -> complete (final BW %.1f, frequency offset %.1f)", sigBw, ofs);
	return ofs;
}

double DownSampleChannelizer::setFilterChain(const std::vector<unsigned int>& stageIndexes)
{
    // filters are described from lower to upper level but the chain is constructed the other way round
    std::vector<unsigned int>::const_reverse_iterator rit = stageIndexes.rbegin();
    double ofs = 0.0, ofs_stage = 0.25;

    // Each index is a base 3 number with 0 = low, 1 = center, 2 = high
    // Functions at upper level will convert a number to base 3 to describe the filter chain. Common converting
    // algorithms will go from LSD to MSD. This explains the reverse order.
    for (; rit != stageIndexes.rend(); ++rit)
    {
        if (*rit == 0)
        {
            m_filterStages.push_back(new FilterStage(FilterStage::ModeLowerHalf));
            ofs -= ofs_stage;
            qDebug("DownSampleChannelizer::setFilterChain: lower half: ofs: %f", ofs);
        }
        else if (*rit == 1)
        {
            m_filterStages.push_back(new FilterStage(FilterStage::ModeCenter));
            qDebug("DownSampleChannelizer::setFilterChain: center: ofs: %f", ofs);
        }
        else if (*rit == 2)
        {
            m_filterStages.push_back(new FilterStage(FilterStage::ModeUpperHalf));
            ofs += ofs_stage;
            qDebug("DownSampleChannelizer::setFilterChain: upper half: ofs: %f", ofs);
        }
    }

    return ofs;
}

void DownSampleChannelizer::freeFilterChain()
{
	for(FilterStages::iterator it = m_filterStages.begin(); it != m_filterStages.end(); ++it)
		delete *it;
	m_filterStages.clear();
}

void DownSampleChannelizer::debugFilterChain()
{
    qDebug("DownSampleChannelizer::debugFilterChain: %lu stages", m_filterStages.size());

    for(FilterStages::iterator it = m_filterStages.begin(); it != m_filterStages.end(); ++it)
    {
        switch ((*it)->m_mode)
        {
        case FilterStage::ModeCenter:
            qDebug("DownSampleChannelizer::debugFilterChain: center %s", (*it)->m_sse ? "sse" : "no_sse");
            break;
        case FilterStage::ModeLowerHalf:
            qDebug("DownSampleChannelizer::debugFilterChain: lower %s", (*it)->m_sse ? "sse" : "no_sse");
            break;
        case FilterStage::ModeUpperHalf:
            qDebug("DownSampleChannelizer::debugFilterChain: upper %s", (*it)->m_sse ? "sse" : "no_sse");
            break;
        default:
            qDebug("DownSampleChannelizer::debugFilterChain: none %s", (*it)->m_sse ? "sse" : "no_sse");
            break;
        }
    }
}