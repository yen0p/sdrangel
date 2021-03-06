///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Edouard Griffiths, F4EXB.                                  //
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

#ifndef SDRBASE_DSP_GLSPECTRUMSETTNGS_H
#define SDRBASE_DSP_GLSPECTRUMSETTNGS_H

#include <QByteArray>

#include "export.h"
#include "dsp/dsptypes.h"
#include "dsp/fftwindow.h"
#include "settings/serializable.h"

class SDRBASE_API GLSpectrumSettings : public Serializable
{
public:
    enum AveragingMode
    {
        AvgModeNone,
        AvgModeMoving,
        AvgModeFixed,
        AvgModeMax
    };

	unsigned int m_fftSize;
	int m_fftOverlap;
	FFTWindow::Function m_fftWindow;
	Real m_refLevel;
	Real m_powerRange;
	int m_decay;
	int m_decayDivisor;
	int m_histogramStroke;
	int m_displayGridIntensity;
	int m_displayTraceIntensity;
	bool m_displayWaterfall;
	bool m_invertedWaterfall;
    Real m_waterfallShare;
	bool m_displayMaxHold;
	bool m_displayCurrent;
	bool m_displayHistogram;
	bool m_displayGrid;
	AveragingMode m_averagingMode;
	int m_averagingIndex;
	unsigned int m_averagingValue;
	bool m_linear; //!< linear else logarithmic scale
    bool m_ssb;    //!< SSB display with spectrum center at start of array or display - else spectrum center is on center
    bool m_usb;    //!< USB display with increasing frequencies towads the right - else decreasing frequencies
    QString m_wsSpectrumAddress;
    uint16_t m_wsSpectrumPort;

    GLSpectrumSettings();
	virtual ~GLSpectrumSettings();
    void resetToDefaults();

    virtual QByteArray serialize() const;
    virtual bool deserialize(const QByteArray& data);

    static int getAveragingMaxScale(AveragingMode averagingMode);
    static int getAveragingValue(int averagingIndex, AveragingMode averagingMode);
    static int getAveragingIndex(int averagingValue, AveragingMode averagingMode);
};

#endif // SDRBASE_DSP_GLSPECTRUMSETTNGS_H
