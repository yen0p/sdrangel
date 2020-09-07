/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 5.9.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

/*
 * SWGMetisMISOSettings.h
 *
 * MetisMISOSettings
 */

#ifndef SWGMetisMISOSettings_H_
#define SWGMetisMISOSettings_H_

#include <QJsonObject>


#include <QList>
#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGSDRangel {

class SWG_API SWGMetisMISOSettings: public SWGObject {
public:
    SWGMetisMISOSettings();
    SWGMetisMISOSettings(QString* json);
    virtual ~SWGMetisMISOSettings();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGMetisMISOSettings* fromJson(QString &jsonString) override;

    qint32 getNbReceivers();
    void setNbReceivers(qint32 nb_receivers);

    qint32 getTxEnable();
    void setTxEnable(qint32 tx_enable);

    QList<qint64>* getRxCenterFrequencies();
    void setRxCenterFrequencies(QList<qint64>* rx_center_frequencies);

    qint64 getTxCenterFrequency();
    void setTxCenterFrequency(qint64 tx_center_frequency);

    QList<qint32>* getRxSubsamplingIndexes();
    void setRxSubsamplingIndexes(QList<qint32>* rx_subsampling_indexes);

    qint32 getSampleRateIndex();
    void setSampleRateIndex(qint32 sample_rate_index);

    qint32 getLog2Decim();
    void setLog2Decim(qint32 log2_decim);

    qint32 getPreamp();
    void setPreamp(qint32 preamp);

    qint32 getRandom();
    void setRandom(qint32 random);

    qint32 getDither();
    void setDither(qint32 dither);

    qint32 getDuplex();
    void setDuplex(qint32 duplex);

    qint32 getDcBlock();
    void setDcBlock(qint32 dc_block);

    qint32 getIqCorrection();
    void setIqCorrection(qint32 iq_correction);

    qint32 getTxDrive();
    void setTxDrive(qint32 tx_drive);

    qint32 getUseReverseApi();
    void setUseReverseApi(qint32 use_reverse_api);

    QString* getReverseApiAddress();
    void setReverseApiAddress(QString* reverse_api_address);

    qint32 getReverseApiPort();
    void setReverseApiPort(qint32 reverse_api_port);

    qint32 getReverseApiDeviceIndex();
    void setReverseApiDeviceIndex(qint32 reverse_api_device_index);


    virtual bool isSet() override;

private:
    qint32 nb_receivers;
    bool m_nb_receivers_isSet;

    qint32 tx_enable;
    bool m_tx_enable_isSet;

    QList<qint64>* rx_center_frequencies;
    bool m_rx_center_frequencies_isSet;

    qint64 tx_center_frequency;
    bool m_tx_center_frequency_isSet;

    QList<qint32>* rx_subsampling_indexes;
    bool m_rx_subsampling_indexes_isSet;

    qint32 sample_rate_index;
    bool m_sample_rate_index_isSet;

    qint32 log2_decim;
    bool m_log2_decim_isSet;

    qint32 preamp;
    bool m_preamp_isSet;

    qint32 random;
    bool m_random_isSet;

    qint32 dither;
    bool m_dither_isSet;

    qint32 duplex;
    bool m_duplex_isSet;

    qint32 dc_block;
    bool m_dc_block_isSet;

    qint32 iq_correction;
    bool m_iq_correction_isSet;

    qint32 tx_drive;
    bool m_tx_drive_isSet;

    qint32 use_reverse_api;
    bool m_use_reverse_api_isSet;

    QString* reverse_api_address;
    bool m_reverse_api_address_isSet;

    qint32 reverse_api_port;
    bool m_reverse_api_port_isSet;

    qint32 reverse_api_device_index;
    bool m_reverse_api_device_index_isSet;

};

}

#endif /* SWGMetisMISOSettings_H_ */
