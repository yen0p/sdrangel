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


#include "SWGDVSerialDevice.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGDVSerialDevice::SWGDVSerialDevice(QString* json) {
    init();
    this->fromJson(*json);
}

SWGDVSerialDevice::SWGDVSerialDevice() {
    device_name = nullptr;
    m_device_name_isSet = false;
}

SWGDVSerialDevice::~SWGDVSerialDevice() {
    this->cleanup();
}

void
SWGDVSerialDevice::init() {
    device_name = new QString("");
    m_device_name_isSet = false;
}

void
SWGDVSerialDevice::cleanup() {
    if(device_name != nullptr) { 
        delete device_name;
    }
}

SWGDVSerialDevice*
SWGDVSerialDevice::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGDVSerialDevice::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&device_name, pJson["deviceName"], "QString", "QString");
    
}

QString
SWGDVSerialDevice::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGDVSerialDevice::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(device_name != nullptr && *device_name != QString("")){
        toJsonValue(QString("deviceName"), device_name, obj, QString("QString"));
    }

    return obj;
}

QString*
SWGDVSerialDevice::getDeviceName() {
    return device_name;
}
void
SWGDVSerialDevice::setDeviceName(QString* device_name) {
    this->device_name = device_name;
    this->m_device_name_isSet = true;
}


bool
SWGDVSerialDevice::isSet(){
    bool isObjectUpdated = false;
    do{
        if(device_name && *device_name != QString("")){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

