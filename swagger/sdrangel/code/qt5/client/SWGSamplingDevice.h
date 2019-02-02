/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 4.4.3
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

/*
 * SWGSamplingDevice.h
 *
 * Information about a logical device available from an attached hardware device that can be used as a sampling device
 */

#ifndef SWGSamplingDevice_H_
#define SWGSamplingDevice_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGSDRangel {

class SWG_API SWGSamplingDevice: public SWGObject {
public:
    SWGSamplingDevice();
    SWGSamplingDevice(QString* json);
    virtual ~SWGSamplingDevice();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGSamplingDevice* fromJson(QString &jsonString) override;

    qint32 getIndex();
    void setIndex(qint32 index);

    QString* getHwType();
    void setHwType(QString* hw_type);

    qint32 getTx();
    void setTx(qint32 tx);

    qint32 getNbStreams();
    void setNbStreams(qint32 nb_streams);

    qint32 getStreamIndex();
    void setStreamIndex(qint32 stream_index);

    qint32 getSequence();
    void setSequence(qint32 sequence);

    QString* getSerial();
    void setSerial(QString* serial);

    qint64 getCenterFrequency();
    void setCenterFrequency(qint64 center_frequency);

    qint32 getBandwidth();
    void setBandwidth(qint32 bandwidth);

    QString* getState();
    void setState(QString* state);


    virtual bool isSet() override;

private:
    qint32 index;
    bool m_index_isSet;

    QString* hw_type;
    bool m_hw_type_isSet;

    qint32 tx;
    bool m_tx_isSet;

    qint32 nb_streams;
    bool m_nb_streams_isSet;

    qint32 stream_index;
    bool m_stream_index_isSet;

    qint32 sequence;
    bool m_sequence_isSet;

    QString* serial;
    bool m_serial_isSet;

    qint64 center_frequency;
    bool m_center_frequency_isSet;

    qint32 bandwidth;
    bool m_bandwidth_isSet;

    QString* state;
    bool m_state_isSet;

};

}

#endif /* SWGSamplingDevice_H_ */
