///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2018 Edouard Griffiths, F4EXB                                   //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <errno.h>

#include "dsp/samplesinkfifo.h"
#include "airspyhffthread.h"

AirspyHFFThread *AirspyHFFThread::m_this = 0;

AirspyHFFThread::AirspyHFFThread(airspyhf_device_t* dev, SampleSinkFifo* sampleFifo, QObject* parent) :
	QThread(parent),
	m_running(false),
	m_dev(dev),
	m_convertBuffer(AIRSPYHFF_BLOCKSIZE),
	m_sampleFifo(sampleFifo),
	m_samplerate(10),
	m_log2Decim(0)
{
	m_this = this;
}

AirspyHFFThread::~AirspyHFFThread()
{
	stopWork();
	m_this = 0;
}

void AirspyHFFThread::startWork()
{
	m_startWaitMutex.lock();
	start();
	while(!m_running)
		m_startWaiter.wait(&m_startWaitMutex, 100);
	m_startWaitMutex.unlock();
}

void AirspyHFFThread::stopWork()
{
	qDebug("AirspyThread::stopWork");
	m_running = false;
	wait();
}

void AirspyHFFThread::setSamplerate(uint32_t samplerate)
{
	m_samplerate = samplerate;
}

void AirspyHFFThread::setLog2Decimation(unsigned int log2_decim)
{
	m_log2Decim = log2_decim;
}

void AirspyHFFThread::run()
{
    airspyhf_error rc;

	m_running = true;
	m_startWaiter.wakeAll();

	rc = (airspyhf_error) airspyhf_start(m_dev, rx_callback, 0);

	if (rc != AIRSPYHF_SUCCESS)
	{
		qCritical("AirspyHFFThread::run: failed to start Airspy HF Rx");
	}
	else
	{
		while ((m_running) && (airspyhf_is_streaming(m_dev) != 0))
		{
			sleep(1);
		}
	}

	rc = (airspyhf_error) airspyhf_stop(m_dev);

	if (rc == AIRSPYHF_SUCCESS) {
		qDebug("AirspyHFFThread::run: stopped Airspy HF Rx");
	} else {
		qDebug("AirspyHFFThread::run: failed to stop Airspy HF Rx");
	}

	m_running = false;
}

//  Decimate according to specified log2 (ex: log2=4 => decim=16)
void AirspyHFFThread::callback(const qint16* buf, qint32 len)
{
	SampleVector::iterator it = m_convertBuffer.begin();

    switch (m_log2Decim)
    {
    case 0:
        m_decimators.decimate1(&it, buf, len);
        break;
    case 1:
        m_decimators.decimate2_cen(&it, buf, len);
        break;
    case 2:
        m_decimators.decimate4_cen(&it, buf, len);
        break;
    case 3:
        m_decimators.decimate8_cen(&it, buf, len);
        break;
    case 4:
        m_decimators.decimate16_cen(&it, buf, len);
        break;
    case 5:
        m_decimators.decimate32_cen(&it, buf, len);
        break;
    case 6:
        m_decimators.decimate64_cen(&it, buf, len);
        break;
    default:
        break;
    }

	m_sampleFifo->write(m_convertBuffer.begin(), it);
}


int AirspyHFFThread::rx_callback(airspyhf_transfer_t* transfer)
{
	qint32 bytes_to_write = transfer->sample_count * sizeof(qint16);
	m_this->callback((qint16 *) transfer->samples, bytes_to_write);
	return 0;
}
