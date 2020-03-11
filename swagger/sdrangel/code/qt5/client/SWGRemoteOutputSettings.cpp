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


#include "SWGRemoteOutputSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGRemoteOutputSettings::SWGRemoteOutputSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGRemoteOutputSettings::SWGRemoteOutputSettings() {
    center_frequency = 0;
    m_center_frequency_isSet = false;
    sample_rate = 0;
    m_sample_rate_isSet = false;
    tx_delay = 0.0f;
    m_tx_delay_isSet = false;
    nb_fec_blocks = 0;
    m_nb_fec_blocks_isSet = false;
    api_address = nullptr;
    m_api_address_isSet = false;
    api_port = 0;
    m_api_port_isSet = false;
    data_address = nullptr;
    m_data_address_isSet = false;
    data_port = 0;
    m_data_port_isSet = false;
    device_index = 0;
    m_device_index_isSet = false;
    channel_index = 0;
    m_channel_index_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = nullptr;
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
}

SWGRemoteOutputSettings::~SWGRemoteOutputSettings() {
    this->cleanup();
}

void
SWGRemoteOutputSettings::init() {
    center_frequency = 0;
    m_center_frequency_isSet = false;
    sample_rate = 0;
    m_sample_rate_isSet = false;
    tx_delay = 0.0f;
    m_tx_delay_isSet = false;
    nb_fec_blocks = 0;
    m_nb_fec_blocks_isSet = false;
    api_address = new QString("");
    m_api_address_isSet = false;
    api_port = 0;
    m_api_port_isSet = false;
    data_address = new QString("");
    m_data_address_isSet = false;
    data_port = 0;
    m_data_port_isSet = false;
    device_index = 0;
    m_device_index_isSet = false;
    channel_index = 0;
    m_channel_index_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = new QString("");
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
}

void
SWGRemoteOutputSettings::cleanup() {




    if(api_address != nullptr) { 
        delete api_address;
    }

    if(data_address != nullptr) { 
        delete data_address;
    }




    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }


}

SWGRemoteOutputSettings*
SWGRemoteOutputSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGRemoteOutputSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&center_frequency, pJson["centerFrequency"], "qint32", "");
    
    ::SWGSDRangel::setValue(&sample_rate, pJson["sampleRate"], "qint32", "");
    
    ::SWGSDRangel::setValue(&tx_delay, pJson["txDelay"], "float", "");
    
    ::SWGSDRangel::setValue(&nb_fec_blocks, pJson["nbFECBlocks"], "qint32", "");
    
    ::SWGSDRangel::setValue(&api_address, pJson["apiAddress"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&api_port, pJson["apiPort"], "qint32", "");
    
    ::SWGSDRangel::setValue(&data_address, pJson["dataAddress"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&data_port, pJson["dataPort"], "qint32", "");
    
    ::SWGSDRangel::setValue(&device_index, pJson["deviceIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&channel_index, pJson["channelIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_device_index, pJson["reverseAPIDeviceIndex"], "qint32", "");
    
}

QString
SWGRemoteOutputSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGRemoteOutputSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_center_frequency_isSet){
        obj->insert("centerFrequency", QJsonValue(center_frequency));
    }
    if(m_sample_rate_isSet){
        obj->insert("sampleRate", QJsonValue(sample_rate));
    }
    if(m_tx_delay_isSet){
        obj->insert("txDelay", QJsonValue(tx_delay));
    }
    if(m_nb_fec_blocks_isSet){
        obj->insert("nbFECBlocks", QJsonValue(nb_fec_blocks));
    }
    if(api_address != nullptr && *api_address != QString("")){
        toJsonValue(QString("apiAddress"), api_address, obj, QString("QString"));
    }
    if(m_api_port_isSet){
        obj->insert("apiPort", QJsonValue(api_port));
    }
    if(data_address != nullptr && *data_address != QString("")){
        toJsonValue(QString("dataAddress"), data_address, obj, QString("QString"));
    }
    if(m_data_port_isSet){
        obj->insert("dataPort", QJsonValue(data_port));
    }
    if(m_device_index_isSet){
        obj->insert("deviceIndex", QJsonValue(device_index));
    }
    if(m_channel_index_isSet){
        obj->insert("channelIndex", QJsonValue(channel_index));
    }
    if(m_use_reverse_api_isSet){
        obj->insert("useReverseAPI", QJsonValue(use_reverse_api));
    }
    if(reverse_api_address != nullptr && *reverse_api_address != QString("")){
        toJsonValue(QString("reverseAPIAddress"), reverse_api_address, obj, QString("QString"));
    }
    if(m_reverse_api_port_isSet){
        obj->insert("reverseAPIPort", QJsonValue(reverse_api_port));
    }
    if(m_reverse_api_device_index_isSet){
        obj->insert("reverseAPIDeviceIndex", QJsonValue(reverse_api_device_index));
    }

    return obj;
}

qint32
SWGRemoteOutputSettings::getCenterFrequency() {
    return center_frequency;
}
void
SWGRemoteOutputSettings::setCenterFrequency(qint32 center_frequency) {
    this->center_frequency = center_frequency;
    this->m_center_frequency_isSet = true;
}

qint32
SWGRemoteOutputSettings::getSampleRate() {
    return sample_rate;
}
void
SWGRemoteOutputSettings::setSampleRate(qint32 sample_rate) {
    this->sample_rate = sample_rate;
    this->m_sample_rate_isSet = true;
}

float
SWGRemoteOutputSettings::getTxDelay() {
    return tx_delay;
}
void
SWGRemoteOutputSettings::setTxDelay(float tx_delay) {
    this->tx_delay = tx_delay;
    this->m_tx_delay_isSet = true;
}

qint32
SWGRemoteOutputSettings::getNbFecBlocks() {
    return nb_fec_blocks;
}
void
SWGRemoteOutputSettings::setNbFecBlocks(qint32 nb_fec_blocks) {
    this->nb_fec_blocks = nb_fec_blocks;
    this->m_nb_fec_blocks_isSet = true;
}

QString*
SWGRemoteOutputSettings::getApiAddress() {
    return api_address;
}
void
SWGRemoteOutputSettings::setApiAddress(QString* api_address) {
    this->api_address = api_address;
    this->m_api_address_isSet = true;
}

qint32
SWGRemoteOutputSettings::getApiPort() {
    return api_port;
}
void
SWGRemoteOutputSettings::setApiPort(qint32 api_port) {
    this->api_port = api_port;
    this->m_api_port_isSet = true;
}

QString*
SWGRemoteOutputSettings::getDataAddress() {
    return data_address;
}
void
SWGRemoteOutputSettings::setDataAddress(QString* data_address) {
    this->data_address = data_address;
    this->m_data_address_isSet = true;
}

qint32
SWGRemoteOutputSettings::getDataPort() {
    return data_port;
}
void
SWGRemoteOutputSettings::setDataPort(qint32 data_port) {
    this->data_port = data_port;
    this->m_data_port_isSet = true;
}

qint32
SWGRemoteOutputSettings::getDeviceIndex() {
    return device_index;
}
void
SWGRemoteOutputSettings::setDeviceIndex(qint32 device_index) {
    this->device_index = device_index;
    this->m_device_index_isSet = true;
}

qint32
SWGRemoteOutputSettings::getChannelIndex() {
    return channel_index;
}
void
SWGRemoteOutputSettings::setChannelIndex(qint32 channel_index) {
    this->channel_index = channel_index;
    this->m_channel_index_isSet = true;
}

qint32
SWGRemoteOutputSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGRemoteOutputSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGRemoteOutputSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGRemoteOutputSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGRemoteOutputSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGRemoteOutputSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGRemoteOutputSettings::getReverseApiDeviceIndex() {
    return reverse_api_device_index;
}
void
SWGRemoteOutputSettings::setReverseApiDeviceIndex(qint32 reverse_api_device_index) {
    this->reverse_api_device_index = reverse_api_device_index;
    this->m_reverse_api_device_index_isSet = true;
}


bool
SWGRemoteOutputSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_center_frequency_isSet){
            isObjectUpdated = true; break;
        }
        if(m_sample_rate_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tx_delay_isSet){
            isObjectUpdated = true; break;
        }
        if(m_nb_fec_blocks_isSet){
            isObjectUpdated = true; break;
        }
        if(api_address && *api_address != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_api_port_isSet){
            isObjectUpdated = true; break;
        }
        if(data_address && *data_address != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_data_port_isSet){
            isObjectUpdated = true; break;
        }
        if(m_device_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_channel_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_use_reverse_api_isSet){
            isObjectUpdated = true; break;
        }
        if(reverse_api_address && *reverse_api_address != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_reverse_api_port_isSet){
            isObjectUpdated = true; break;
        }
        if(m_reverse_api_device_index_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

