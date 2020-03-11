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


#include "SWGAudioDevices.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGAudioDevices::SWGAudioDevices(QString* json) {
    init();
    this->fromJson(*json);
}

SWGAudioDevices::SWGAudioDevices() {
    nb_input_devices = 0;
    m_nb_input_devices_isSet = false;
    input_devices = nullptr;
    m_input_devices_isSet = false;
    nb_output_devices = 0;
    m_nb_output_devices_isSet = false;
    output_devices = nullptr;
    m_output_devices_isSet = false;
}

SWGAudioDevices::~SWGAudioDevices() {
    this->cleanup();
}

void
SWGAudioDevices::init() {
    nb_input_devices = 0;
    m_nb_input_devices_isSet = false;
    input_devices = new QList<SWGAudioInputDevice*>();
    m_input_devices_isSet = false;
    nb_output_devices = 0;
    m_nb_output_devices_isSet = false;
    output_devices = new QList<SWGAudioOutputDevice*>();
    m_output_devices_isSet = false;
}

void
SWGAudioDevices::cleanup() {

    if(input_devices != nullptr) { 
        auto arr = input_devices;
        for(auto o: *arr) { 
            delete o;
        }
        delete input_devices;
    }

    if(output_devices != nullptr) { 
        auto arr = output_devices;
        for(auto o: *arr) { 
            delete o;
        }
        delete output_devices;
    }
}

SWGAudioDevices*
SWGAudioDevices::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGAudioDevices::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&nb_input_devices, pJson["nbInputDevices"], "qint32", "");
    
    
    ::SWGSDRangel::setValue(&input_devices, pJson["inputDevices"], "QList", "SWGAudioInputDevice");
    ::SWGSDRangel::setValue(&nb_output_devices, pJson["nbOutputDevices"], "qint32", "");
    
    
    ::SWGSDRangel::setValue(&output_devices, pJson["outputDevices"], "QList", "SWGAudioOutputDevice");
}

QString
SWGAudioDevices::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGAudioDevices::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_nb_input_devices_isSet){
        obj->insert("nbInputDevices", QJsonValue(nb_input_devices));
    }
    if(input_devices && input_devices->size() > 0){
        toJsonArray((QList<void*>*)input_devices, obj, "inputDevices", "SWGAudioInputDevice");
    }
    if(m_nb_output_devices_isSet){
        obj->insert("nbOutputDevices", QJsonValue(nb_output_devices));
    }
    if(output_devices && output_devices->size() > 0){
        toJsonArray((QList<void*>*)output_devices, obj, "outputDevices", "SWGAudioOutputDevice");
    }

    return obj;
}

qint32
SWGAudioDevices::getNbInputDevices() {
    return nb_input_devices;
}
void
SWGAudioDevices::setNbInputDevices(qint32 nb_input_devices) {
    this->nb_input_devices = nb_input_devices;
    this->m_nb_input_devices_isSet = true;
}

QList<SWGAudioInputDevice*>*
SWGAudioDevices::getInputDevices() {
    return input_devices;
}
void
SWGAudioDevices::setInputDevices(QList<SWGAudioInputDevice*>* input_devices) {
    this->input_devices = input_devices;
    this->m_input_devices_isSet = true;
}

qint32
SWGAudioDevices::getNbOutputDevices() {
    return nb_output_devices;
}
void
SWGAudioDevices::setNbOutputDevices(qint32 nb_output_devices) {
    this->nb_output_devices = nb_output_devices;
    this->m_nb_output_devices_isSet = true;
}

QList<SWGAudioOutputDevice*>*
SWGAudioDevices::getOutputDevices() {
    return output_devices;
}
void
SWGAudioDevices::setOutputDevices(QList<SWGAudioOutputDevice*>* output_devices) {
    this->output_devices = output_devices;
    this->m_output_devices_isSet = true;
}


bool
SWGAudioDevices::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_nb_input_devices_isSet){
            isObjectUpdated = true; break;
        }
        if(input_devices && (input_devices->size() > 0)){
            isObjectUpdated = true; break;
        }
        if(m_nb_output_devices_isSet){
            isObjectUpdated = true; break;
        }
        if(output_devices && (output_devices->size() > 0)){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

