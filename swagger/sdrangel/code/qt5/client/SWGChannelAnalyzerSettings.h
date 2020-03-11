/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 4.14.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

/*
 * SWGChannelAnalyzerSettings.h
 *
 * ChannelAnalyzer
 */

#ifndef SWGChannelAnalyzerSettings_H_
#define SWGChannelAnalyzerSettings_H_

#include <QJsonObject>


#include "SWGGLScope.h"
#include "SWGGLSpectrum.h"
#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGSDRangel {

class SWG_API SWGChannelAnalyzerSettings: public SWGObject {
public:
    SWGChannelAnalyzerSettings();
    SWGChannelAnalyzerSettings(QString* json);
    virtual ~SWGChannelAnalyzerSettings();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGChannelAnalyzerSettings* fromJson(QString &jsonString) override;

    qint32 getFrequency();
    void setFrequency(qint32 frequency);

    qint32 getDownSample();
    void setDownSample(qint32 down_sample);

    qint32 getDownSampleRate();
    void setDownSampleRate(qint32 down_sample_rate);

    qint32 getBandwidth();
    void setBandwidth(qint32 bandwidth);

    qint32 getLowCutoff();
    void setLowCutoff(qint32 low_cutoff);

    qint32 getSpanLog2();
    void setSpanLog2(qint32 span_log2);

    qint32 getSsb();
    void setSsb(qint32 ssb);

    qint32 getPll();
    void setPll(qint32 pll);

    qint32 getFll();
    void setFll(qint32 fll);

    qint32 getRrc();
    void setRrc(qint32 rrc);

    qint32 getRrcRolloff();
    void setRrcRolloff(qint32 rrc_rolloff);

    qint32 getPllPskOrder();
    void setPllPskOrder(qint32 pll_psk_order);

    qint32 getInputType();
    void setInputType(qint32 input_type);

    qint32 getRgbColor();
    void setRgbColor(qint32 rgb_color);

    QString* getTitle();
    void setTitle(QString* title);

    SWGGLSpectrum* getSpectrumConfig();
    void setSpectrumConfig(SWGGLSpectrum* spectrum_config);

    SWGGLScope* getScopeConfig();
    void setScopeConfig(SWGGLScope* scope_config);


    virtual bool isSet() override;

private:
    qint32 frequency;
    bool m_frequency_isSet;

    qint32 down_sample;
    bool m_down_sample_isSet;

    qint32 down_sample_rate;
    bool m_down_sample_rate_isSet;

    qint32 bandwidth;
    bool m_bandwidth_isSet;

    qint32 low_cutoff;
    bool m_low_cutoff_isSet;

    qint32 span_log2;
    bool m_span_log2_isSet;

    qint32 ssb;
    bool m_ssb_isSet;

    qint32 pll;
    bool m_pll_isSet;

    qint32 fll;
    bool m_fll_isSet;

    qint32 rrc;
    bool m_rrc_isSet;

    qint32 rrc_rolloff;
    bool m_rrc_rolloff_isSet;

    qint32 pll_psk_order;
    bool m_pll_psk_order_isSet;

    qint32 input_type;
    bool m_input_type_isSet;

    qint32 rgb_color;
    bool m_rgb_color_isSet;

    QString* title;
    bool m_title_isSet;

    SWGGLSpectrum* spectrum_config;
    bool m_spectrum_config_isSet;

    SWGGLScope* scope_config;
    bool m_scope_config_isSet;

};

}

#endif /* SWGChannelAnalyzerSettings_H_ */
