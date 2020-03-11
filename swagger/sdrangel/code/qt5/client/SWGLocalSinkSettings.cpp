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


#include "SWGLocalSinkSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGLocalSinkSettings::SWGLocalSinkSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGLocalSinkSettings::SWGLocalSinkSettings() {
    local_device_index = 0;
    m_local_device_index_isSet = false;
    rgb_color = 0;
    m_rgb_color_isSet = false;
    title = nullptr;
    m_title_isSet = false;
    log2_decim = 0;
    m_log2_decim_isSet = false;
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

SWGLocalSinkSettings::~SWGLocalSinkSettings() {
    this->cleanup();
}

void
SWGLocalSinkSettings::init() {
    local_device_index = 0;
    m_local_device_index_isSet = false;
    rgb_color = 0;
    m_rgb_color_isSet = false;
    title = new QString("");
    m_title_isSet = false;
    log2_decim = 0;
    m_log2_decim_isSet = false;
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
SWGLocalSinkSettings::cleanup() {


    if(title != nullptr) { 
        delete title;
    }





    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }



}

SWGLocalSinkSettings*
SWGLocalSinkSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGLocalSinkSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&local_device_index, pJson["localDeviceIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&rgb_color, pJson["rgbColor"], "qint32", "");
    
    ::SWGSDRangel::setValue(&title, pJson["title"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&log2_decim, pJson["log2Decim"], "qint32", "");
    
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
SWGLocalSinkSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGLocalSinkSettings::asJsonObject() {
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
    if(m_log2_decim_isSet){
        obj->insert("log2Decim", QJsonValue(log2_decim));
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
SWGLocalSinkSettings::getLocalDeviceIndex() {
    return local_device_index;
}
void
SWGLocalSinkSettings::setLocalDeviceIndex(qint32 local_device_index) {
    this->local_device_index = local_device_index;
    this->m_local_device_index_isSet = true;
}

qint32
SWGLocalSinkSettings::getRgbColor() {
    return rgb_color;
}
void
SWGLocalSinkSettings::setRgbColor(qint32 rgb_color) {
    this->rgb_color = rgb_color;
    this->m_rgb_color_isSet = true;
}

QString*
SWGLocalSinkSettings::getTitle() {
    return title;
}
void
SWGLocalSinkSettings::setTitle(QString* title) {
    this->title = title;
    this->m_title_isSet = true;
}

qint32
SWGLocalSinkSettings::getLog2Decim() {
    return log2_decim;
}
void
SWGLocalSinkSettings::setLog2Decim(qint32 log2_decim) {
    this->log2_decim = log2_decim;
    this->m_log2_decim_isSet = true;
}

qint32
SWGLocalSinkSettings::getFilterChainHash() {
    return filter_chain_hash;
}
void
SWGLocalSinkSettings::setFilterChainHash(qint32 filter_chain_hash) {
    this->filter_chain_hash = filter_chain_hash;
    this->m_filter_chain_hash_isSet = true;
}

qint32
SWGLocalSinkSettings::getPlay() {
    return play;
}
void
SWGLocalSinkSettings::setPlay(qint32 play) {
    this->play = play;
    this->m_play_isSet = true;
}

qint32
SWGLocalSinkSettings::getStreamIndex() {
    return stream_index;
}
void
SWGLocalSinkSettings::setStreamIndex(qint32 stream_index) {
    this->stream_index = stream_index;
    this->m_stream_index_isSet = true;
}

qint32
SWGLocalSinkSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGLocalSinkSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGLocalSinkSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGLocalSinkSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGLocalSinkSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGLocalSinkSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGLocalSinkSettings::getReverseApiDeviceIndex() {
    return reverse_api_device_index;
}
void
SWGLocalSinkSettings::setReverseApiDeviceIndex(qint32 reverse_api_device_index) {
    this->reverse_api_device_index = reverse_api_device_index;
    this->m_reverse_api_device_index_isSet = true;
}

qint32
SWGLocalSinkSettings::getReverseApiChannelIndex() {
    return reverse_api_channel_index;
}
void
SWGLocalSinkSettings::setReverseApiChannelIndex(qint32 reverse_api_channel_index) {
    this->reverse_api_channel_index = reverse_api_channel_index;
    this->m_reverse_api_channel_index_isSet = true;
}


bool
SWGLocalSinkSettings::isSet(){
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
        if(m_log2_decim_isSet){
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

