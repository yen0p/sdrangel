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


#include "SWGLocalSourceSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGLocalSourceSettings::SWGLocalSourceSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGLocalSourceSettings::SWGLocalSourceSettings() {
    local_device_index = 0;
    m_local_device_index_isSet = false;
    rgb_color = 0;
    m_rgb_color_isSet = false;
    title = nullptr;
    m_title_isSet = false;
    log2_interp = 0;
    m_log2_interp_isSet = false;
    filter_chain_hash = 0;
    m_filter_chain_hash_isSet = false;
    play = 0;
    m_play_isSet = false;
    stream_index = 0;
    m_stream_index_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = nullptr;
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
    reverse_api_channel_index = 0;
    m_reverse_api_channel_index_isSet = false;
}

SWGLocalSourceSettings::~SWGLocalSourceSettings() {
    this->cleanup();
}

void
SWGLocalSourceSettings::init() {
    local_device_index = 0;
    m_local_device_index_isSet = false;
    rgb_color = 0;
    m_rgb_color_isSet = false;
    title = new QString("");
    m_title_isSet = false;
    log2_interp = 0;
    m_log2_interp_isSet = false;
    filter_chain_hash = 0;
    m_filter_chain_hash_isSet = false;
    play = 0;
    m_play_isSet = false;
    stream_index = 0;
    m_stream_index_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = new QString("");
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
    reverse_api_channel_index = 0;
    m_reverse_api_channel_index_isSet = false;
}

void
SWGLocalSourceSettings::cleanup() {


    if(title != nullptr) { 
        delete title;
    }





    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }



}

SWGLocalSourceSettings*
SWGLocalSourceSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGLocalSourceSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&local_device_index, pJson["localDeviceIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&rgb_color, pJson["rgbColor"], "qint32", "");
    
    ::SWGSDRangel::setValue(&title, pJson["title"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&log2_interp, pJson["log2Interp"], "qint32", "");
    
    ::SWGSDRangel::setValue(&filter_chain_hash, pJson["filterChainHash"], "qint32", "");
    
    ::SWGSDRangel::setValue(&play, pJson["play"], "qint32", "");
    
    ::SWGSDRangel::setValue(&stream_index, pJson["streamIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_device_index, pJson["reverseAPIDeviceIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_channel_index, pJson["reverseAPIChannelIndex"], "qint32", "");
    
}

QString
SWGLocalSourceSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGLocalSourceSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_local_device_index_isSet){
        obj->insert("localDeviceIndex", QJsonValue(local_device_index));
    }
    if(m_rgb_color_isSet){
        obj->insert("rgbColor", QJsonValue(rgb_color));
    }
    if(title != nullptr && *title != QString("")){
        toJsonValue(QString("title"), title, obj, QString("QString"));
    }
    if(m_log2_interp_isSet){
        obj->insert("log2Interp", QJsonValue(log2_interp));
    }
    if(m_filter_chain_hash_isSet){
        obj->insert("filterChainHash", QJsonValue(filter_chain_hash));
    }
    if(m_play_isSet){
        obj->insert("play", QJsonValue(play));
    }
    if(m_stream_index_isSet){
        obj->insert("streamIndex", QJsonValue(stream_index));
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
    if(m_reverse_api_channel_index_isSet){
        obj->insert("reverseAPIChannelIndex", QJsonValue(reverse_api_channel_index));
    }

    return obj;
}

qint32
SWGLocalSourceSettings::getLocalDeviceIndex() {
    return local_device_index;
}
void
SWGLocalSourceSettings::setLocalDeviceIndex(qint32 local_device_index) {
    this->local_device_index = local_device_index;
    this->m_local_device_index_isSet = true;
}

qint32
SWGLocalSourceSettings::getRgbColor() {
    return rgb_color;
}
void
SWGLocalSourceSettings::setRgbColor(qint32 rgb_color) {
    this->rgb_color = rgb_color;
    this->m_rgb_color_isSet = true;
}

QString*
SWGLocalSourceSettings::getTitle() {
    return title;
}
void
SWGLocalSourceSettings::setTitle(QString* title) {
    this->title = title;
    this->m_title_isSet = true;
}

qint32
SWGLocalSourceSettings::getLog2Interp() {
    return log2_interp;
}
void
SWGLocalSourceSettings::setLog2Interp(qint32 log2_interp) {
    this->log2_interp = log2_interp;
    this->m_log2_interp_isSet = true;
}

qint32
SWGLocalSourceSettings::getFilterChainHash() {
    return filter_chain_hash;
}
void
SWGLocalSourceSettings::setFilterChainHash(qint32 filter_chain_hash) {
    this->filter_chain_hash = filter_chain_hash;
    this->m_filter_chain_hash_isSet = true;
}

qint32
SWGLocalSourceSettings::getPlay() {
    return play;
}
void
SWGLocalSourceSettings::setPlay(qint32 play) {
    this->play = play;
    this->m_play_isSet = true;
}

qint32
SWGLocalSourceSettings::getStreamIndex() {
    return stream_index;
}
void
SWGLocalSourceSettings::setStreamIndex(qint32 stream_index) {
    this->stream_index = stream_index;
    this->m_stream_index_isSet = true;
}

qint32
SWGLocalSourceSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGLocalSourceSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGLocalSourceSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGLocalSourceSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGLocalSourceSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGLocalSourceSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGLocalSourceSettings::getReverseApiDeviceIndex() {
    return reverse_api_device_index;
}
void
SWGLocalSourceSettings::setReverseApiDeviceIndex(qint32 reverse_api_device_index) {
    this->reverse_api_device_index = reverse_api_device_index;
    this->m_reverse_api_device_index_isSet = true;
}

qint32
SWGLocalSourceSettings::getReverseApiChannelIndex() {
    return reverse_api_channel_index;
}
void
SWGLocalSourceSettings::setReverseApiChannelIndex(qint32 reverse_api_channel_index) {
    this->reverse_api_channel_index = reverse_api_channel_index;
    this->m_reverse_api_channel_index_isSet = true;
}


bool
SWGLocalSourceSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_local_device_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rgb_color_isSet){
            isObjectUpdated = true; break;
        }
        if(title && *title != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_log2_interp_isSet){
            isObjectUpdated = true; break;
        }
        if(m_filter_chain_hash_isSet){
            isObjectUpdated = true; break;
        }
        if(m_play_isSet){
            isObjectUpdated = true; break;
        }
        if(m_stream_index_isSet){
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
        if(m_reverse_api_channel_index_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

