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


#include "SWGPresets.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGPresets::SWGPresets(QString* json) {
    init();
    this->fromJson(*json);
}

SWGPresets::SWGPresets() {
    nb_groups = 0;
    m_nb_groups_isSet = false;
    groups = nullptr;
    m_groups_isSet = false;
}

SWGPresets::~SWGPresets() {
    this->cleanup();
}

void
SWGPresets::init() {
    nb_groups = 0;
    m_nb_groups_isSet = false;
    groups = new QList<SWGPresetGroup*>();
    m_groups_isSet = false;
}

void
SWGPresets::cleanup() {

    if(groups != nullptr) { 
        auto arr = groups;
        for(auto o: *arr) { 
            delete o;
        }
        delete groups;
    }
}

SWGPresets*
SWGPresets::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGPresets::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&nb_groups, pJson["nbGroups"], "qint32", "");
    
    
    ::SWGSDRangel::setValue(&groups, pJson["groups"], "QList", "SWGPresetGroup");
}

QString
SWGPresets::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGPresets::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_nb_groups_isSet){
        obj->insert("nbGroups", QJsonValue(nb_groups));
    }
    if(groups->size() > 0){
        toJsonArray((QList<void*>*)groups, obj, "groups", "SWGPresetGroup");
    }

    return obj;
}

qint32
SWGPresets::getNbGroups() {
    return nb_groups;
}
void
SWGPresets::setNbGroups(qint32 nb_groups) {
    this->nb_groups = nb_groups;
    this->m_nb_groups_isSet = true;
}

QList<SWGPresetGroup*>*
SWGPresets::getGroups() {
    return groups;
}
void
SWGPresets::setGroups(QList<SWGPresetGroup*>* groups) {
    this->groups = groups;
    this->m_groups_isSet = true;
}


bool
SWGPresets::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_nb_groups_isSet){ isObjectUpdated = true; break;}
        if(groups->size() > 0){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}
}

