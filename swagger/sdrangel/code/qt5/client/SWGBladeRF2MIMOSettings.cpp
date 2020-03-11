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


#include "SWGBladeRF2MIMOSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGBladeRF2MIMOSettings::SWGBladeRF2MIMOSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGBladeRF2MIMOSettings::SWGBladeRF2MIMOSettings() {
    dev_sample_rate = 0;
    m_dev_sample_rate_isSet = false;
    l_oppm_tenths = 0;
    m_l_oppm_tenths_isSet = false;
    rx_center_frequency = 0L;
    m_rx_center_frequency_isSet = false;
    log2_decim = 0;
    m_log2_decim_isSet = false;
    fc_pos_rx = 0;
    m_fc_pos_rx_isSet = false;
    rx_bandwidth = 0;
    m_rx_bandwidth_isSet = false;
    rx0_gain_mode = 0;
    m_rx0_gain_mode_isSet = false;
    rx0_global_gain = 0;
    m_rx0_global_gain_isSet = false;
    rx1_gain_mode = 0;
    m_rx1_gain_mode_isSet = false;
    rx1_global_gain = 0;
    m_rx1_global_gain_isSet = false;
    rx_bias_tee = 0;
    m_rx_bias_tee_isSet = false;
    dc_block = 0;
    m_dc_block_isSet = false;
    iq_correction = 0;
    m_iq_correction_isSet = false;
    rx_transverter_mode = 0;
    m_rx_transverter_mode_isSet = false;
    rx_transverter_delta_frequency = 0L;
    m_rx_transverter_delta_frequency_isSet = false;
    tx_center_frequency = 0L;
    m_tx_center_frequency_isSet = false;
    log2_interp = 0;
    m_log2_interp_isSet = false;
    fc_pos_tx = 0;
    m_fc_pos_tx_isSet = false;
    tx_bandwidth = 0;
    m_tx_bandwidth_isSet = false;
    tx0_global_gain = 0;
    m_tx0_global_gain_isSet = false;
    tx1_global_gain = 0;
    m_tx1_global_gain_isSet = false;
    tx_bias_tee = 0;
    m_tx_bias_tee_isSet = false;
    tx_transverter_mode = 0;
    m_tx_transverter_mode_isSet = false;
    tx_transverter_delta_frequency = 0L;
    m_tx_transverter_delta_frequency_isSet = false;
    file_record_name = nullptr;
    m_file_record_name_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = nullptr;
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
}

SWGBladeRF2MIMOSettings::~SWGBladeRF2MIMOSettings() {
    this->cleanup();
}

void
SWGBladeRF2MIMOSettings::init() {
    dev_sample_rate = 0;
    m_dev_sample_rate_isSet = false;
    l_oppm_tenths = 0;
    m_l_oppm_tenths_isSet = false;
    rx_center_frequency = 0L;
    m_rx_center_frequency_isSet = false;
    log2_decim = 0;
    m_log2_decim_isSet = false;
    fc_pos_rx = 0;
    m_fc_pos_rx_isSet = false;
    rx_bandwidth = 0;
    m_rx_bandwidth_isSet = false;
    rx0_gain_mode = 0;
    m_rx0_gain_mode_isSet = false;
    rx0_global_gain = 0;
    m_rx0_global_gain_isSet = false;
    rx1_gain_mode = 0;
    m_rx1_gain_mode_isSet = false;
    rx1_global_gain = 0;
    m_rx1_global_gain_isSet = false;
    rx_bias_tee = 0;
    m_rx_bias_tee_isSet = false;
    dc_block = 0;
    m_dc_block_isSet = false;
    iq_correction = 0;
    m_iq_correction_isSet = false;
    rx_transverter_mode = 0;
    m_rx_transverter_mode_isSet = false;
    rx_transverter_delta_frequency = 0L;
    m_rx_transverter_delta_frequency_isSet = false;
    tx_center_frequency = 0L;
    m_tx_center_frequency_isSet = false;
    log2_interp = 0;
    m_log2_interp_isSet = false;
    fc_pos_tx = 0;
    m_fc_pos_tx_isSet = false;
    tx_bandwidth = 0;
    m_tx_bandwidth_isSet = false;
    tx0_global_gain = 0;
    m_tx0_global_gain_isSet = false;
    tx1_global_gain = 0;
    m_tx1_global_gain_isSet = false;
    tx_bias_tee = 0;
    m_tx_bias_tee_isSet = false;
    tx_transverter_mode = 0;
    m_tx_transverter_mode_isSet = false;
    tx_transverter_delta_frequency = 0L;
    m_tx_transverter_delta_frequency_isSet = false;
    file_record_name = new QString("");
    m_file_record_name_isSet = false;
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
SWGBladeRF2MIMOSettings::cleanup() {
























    if(file_record_name != nullptr) { 
        delete file_record_name;
    }

    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }


}

SWGBladeRF2MIMOSettings*
SWGBladeRF2MIMOSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGBladeRF2MIMOSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&dev_sample_rate, pJson["devSampleRate"], "qint32", "");
    
    ::SWGSDRangel::setValue(&l_oppm_tenths, pJson["LOppmTenths"], "qint32", "");
    
    ::SWGSDRangel::setValue(&rx_center_frequency, pJson["rxCenterFrequency"], "qint64", "");
    
    ::SWGSDRangel::setValue(&log2_decim, pJson["log2Decim"], "qint32", "");
    
    ::SWGSDRangel::setValue(&fc_pos_rx, pJson["fcPosRx"], "qint32", "");
    
    ::SWGSDRangel::setValue(&rx_bandwidth, pJson["rxBandwidth"], "qint32", "");
    
    ::SWGSDRangel::setValue(&rx0_gain_mode, pJson["rx0GainMode"], "qint32", "");
    
    ::SWGSDRangel::setValue(&rx0_global_gain, pJson["rx0GlobalGain"], "qint32", "");
    
    ::SWGSDRangel::setValue(&rx1_gain_mode, pJson["rx1GainMode"], "qint32", "");
    
    ::SWGSDRangel::setValue(&rx1_global_gain, pJson["rx1GlobalGain"], "qint32", "");
    
    ::SWGSDRangel::setValue(&rx_bias_tee, pJson["rxBiasTee"], "qint32", "");
    
    ::SWGSDRangel::setValue(&dc_block, pJson["dcBlock"], "qint32", "");
    
    ::SWGSDRangel::setValue(&iq_correction, pJson["iqCorrection"], "qint32", "");
    
    ::SWGSDRangel::setValue(&rx_transverter_mode, pJson["rxTransverterMode"], "qint32", "");
    
    ::SWGSDRangel::setValue(&rx_transverter_delta_frequency, pJson["rxTransverterDeltaFrequency"], "qint64", "");
    
    ::SWGSDRangel::setValue(&tx_center_frequency, pJson["txCenterFrequency"], "qint64", "");
    
    ::SWGSDRangel::setValue(&log2_interp, pJson["log2Interp"], "qint32", "");
    
    ::SWGSDRangel::setValue(&fc_pos_tx, pJson["fcPosTx"], "qint32", "");
    
    ::SWGSDRangel::setValue(&tx_bandwidth, pJson["txBandwidth"], "qint32", "");
    
    ::SWGSDRangel::setValue(&tx0_global_gain, pJson["tx0GlobalGain"], "qint32", "");
    
    ::SWGSDRangel::setValue(&tx1_global_gain, pJson["tx1GlobalGain"], "qint32", "");
    
    ::SWGSDRangel::setValue(&tx_bias_tee, pJson["txBiasTee"], "qint32", "");
    
    ::SWGSDRangel::setValue(&tx_transverter_mode, pJson["txTransverterMode"], "qint32", "");
    
    ::SWGSDRangel::setValue(&tx_transverter_delta_frequency, pJson["txTransverterDeltaFrequency"], "qint64", "");
    
    ::SWGSDRangel::setValue(&file_record_name, pJson["fileRecordName"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_device_index, pJson["reverseAPIDeviceIndex"], "qint32", "");
    
}

QString
SWGBladeRF2MIMOSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGBladeRF2MIMOSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_dev_sample_rate_isSet){
        obj->insert("devSampleRate", QJsonValue(dev_sample_rate));
    }
    if(m_l_oppm_tenths_isSet){
        obj->insert("LOppmTenths", QJsonValue(l_oppm_tenths));
    }
    if(m_rx_center_frequency_isSet){
        obj->insert("rxCenterFrequency", QJsonValue(rx_center_frequency));
    }
    if(m_log2_decim_isSet){
        obj->insert("log2Decim", QJsonValue(log2_decim));
    }
    if(m_fc_pos_rx_isSet){
        obj->insert("fcPosRx", QJsonValue(fc_pos_rx));
    }
    if(m_rx_bandwidth_isSet){
        obj->insert("rxBandwidth", QJsonValue(rx_bandwidth));
    }
    if(m_rx0_gain_mode_isSet){
        obj->insert("rx0GainMode", QJsonValue(rx0_gain_mode));
    }
    if(m_rx0_global_gain_isSet){
        obj->insert("rx0GlobalGain", QJsonValue(rx0_global_gain));
    }
    if(m_rx1_gain_mode_isSet){
        obj->insert("rx1GainMode", QJsonValue(rx1_gain_mode));
    }
    if(m_rx1_global_gain_isSet){
        obj->insert("rx1GlobalGain", QJsonValue(rx1_global_gain));
    }
    if(m_rx_bias_tee_isSet){
        obj->insert("rxBiasTee", QJsonValue(rx_bias_tee));
    }
    if(m_dc_block_isSet){
        obj->insert("dcBlock", QJsonValue(dc_block));
    }
    if(m_iq_correction_isSet){
        obj->insert("iqCorrection", QJsonValue(iq_correction));
    }
    if(m_rx_transverter_mode_isSet){
        obj->insert("rxTransverterMode", QJsonValue(rx_transverter_mode));
    }
    if(m_rx_transverter_delta_frequency_isSet){
        obj->insert("rxTransverterDeltaFrequency", QJsonValue(rx_transverter_delta_frequency));
    }
    if(m_tx_center_frequency_isSet){
        obj->insert("txCenterFrequency", QJsonValue(tx_center_frequency));
    }
    if(m_log2_interp_isSet){
        obj->insert("log2Interp", QJsonValue(log2_interp));
    }
    if(m_fc_pos_tx_isSet){
        obj->insert("fcPosTx", QJsonValue(fc_pos_tx));
    }
    if(m_tx_bandwidth_isSet){
        obj->insert("txBandwidth", QJsonValue(tx_bandwidth));
    }
    if(m_tx0_global_gain_isSet){
        obj->insert("tx0GlobalGain", QJsonValue(tx0_global_gain));
    }
    if(m_tx1_global_gain_isSet){
        obj->insert("tx1GlobalGain", QJsonValue(tx1_global_gain));
    }
    if(m_tx_bias_tee_isSet){
        obj->insert("txBiasTee", QJsonValue(tx_bias_tee));
    }
    if(m_tx_transverter_mode_isSet){
        obj->insert("txTransverterMode", QJsonValue(tx_transverter_mode));
    }
    if(m_tx_transverter_delta_frequency_isSet){
        obj->insert("txTransverterDeltaFrequency", QJsonValue(tx_transverter_delta_frequency));
    }
    if(file_record_name != nullptr && *file_record_name != QString("")){
        toJsonValue(QString("fileRecordName"), file_record_name, obj, QString("QString"));
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
SWGBladeRF2MIMOSettings::getDevSampleRate() {
    return dev_sample_rate;
}
void
SWGBladeRF2MIMOSettings::setDevSampleRate(qint32 dev_sample_rate) {
    this->dev_sample_rate = dev_sample_rate;
    this->m_dev_sample_rate_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getLOppmTenths() {
    return l_oppm_tenths;
}
void
SWGBladeRF2MIMOSettings::setLOppmTenths(qint32 l_oppm_tenths) {
    this->l_oppm_tenths = l_oppm_tenths;
    this->m_l_oppm_tenths_isSet = true;
}

qint64
SWGBladeRF2MIMOSettings::getRxCenterFrequency() {
    return rx_center_frequency;
}
void
SWGBladeRF2MIMOSettings::setRxCenterFrequency(qint64 rx_center_frequency) {
    this->rx_center_frequency = rx_center_frequency;
    this->m_rx_center_frequency_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getLog2Decim() {
    return log2_decim;
}
void
SWGBladeRF2MIMOSettings::setLog2Decim(qint32 log2_decim) {
    this->log2_decim = log2_decim;
    this->m_log2_decim_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getFcPosRx() {
    return fc_pos_rx;
}
void
SWGBladeRF2MIMOSettings::setFcPosRx(qint32 fc_pos_rx) {
    this->fc_pos_rx = fc_pos_rx;
    this->m_fc_pos_rx_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getRxBandwidth() {
    return rx_bandwidth;
}
void
SWGBladeRF2MIMOSettings::setRxBandwidth(qint32 rx_bandwidth) {
    this->rx_bandwidth = rx_bandwidth;
    this->m_rx_bandwidth_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getRx0GainMode() {
    return rx0_gain_mode;
}
void
SWGBladeRF2MIMOSettings::setRx0GainMode(qint32 rx0_gain_mode) {
    this->rx0_gain_mode = rx0_gain_mode;
    this->m_rx0_gain_mode_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getRx0GlobalGain() {
    return rx0_global_gain;
}
void
SWGBladeRF2MIMOSettings::setRx0GlobalGain(qint32 rx0_global_gain) {
    this->rx0_global_gain = rx0_global_gain;
    this->m_rx0_global_gain_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getRx1GainMode() {
    return rx1_gain_mode;
}
void
SWGBladeRF2MIMOSettings::setRx1GainMode(qint32 rx1_gain_mode) {
    this->rx1_gain_mode = rx1_gain_mode;
    this->m_rx1_gain_mode_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getRx1GlobalGain() {
    return rx1_global_gain;
}
void
SWGBladeRF2MIMOSettings::setRx1GlobalGain(qint32 rx1_global_gain) {
    this->rx1_global_gain = rx1_global_gain;
    this->m_rx1_global_gain_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getRxBiasTee() {
    return rx_bias_tee;
}
void
SWGBladeRF2MIMOSettings::setRxBiasTee(qint32 rx_bias_tee) {
    this->rx_bias_tee = rx_bias_tee;
    this->m_rx_bias_tee_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getDcBlock() {
    return dc_block;
}
void
SWGBladeRF2MIMOSettings::setDcBlock(qint32 dc_block) {
    this->dc_block = dc_block;
    this->m_dc_block_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getIqCorrection() {
    return iq_correction;
}
void
SWGBladeRF2MIMOSettings::setIqCorrection(qint32 iq_correction) {
    this->iq_correction = iq_correction;
    this->m_iq_correction_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getRxTransverterMode() {
    return rx_transverter_mode;
}
void
SWGBladeRF2MIMOSettings::setRxTransverterMode(qint32 rx_transverter_mode) {
    this->rx_transverter_mode = rx_transverter_mode;
    this->m_rx_transverter_mode_isSet = true;
}

qint64
SWGBladeRF2MIMOSettings::getRxTransverterDeltaFrequency() {
    return rx_transverter_delta_frequency;
}
void
SWGBladeRF2MIMOSettings::setRxTransverterDeltaFrequency(qint64 rx_transverter_delta_frequency) {
    this->rx_transverter_delta_frequency = rx_transverter_delta_frequency;
    this->m_rx_transverter_delta_frequency_isSet = true;
}

qint64
SWGBladeRF2MIMOSettings::getTxCenterFrequency() {
    return tx_center_frequency;
}
void
SWGBladeRF2MIMOSettings::setTxCenterFrequency(qint64 tx_center_frequency) {
    this->tx_center_frequency = tx_center_frequency;
    this->m_tx_center_frequency_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getLog2Interp() {
    return log2_interp;
}
void
SWGBladeRF2MIMOSettings::setLog2Interp(qint32 log2_interp) {
    this->log2_interp = log2_interp;
    this->m_log2_interp_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getFcPosTx() {
    return fc_pos_tx;
}
void
SWGBladeRF2MIMOSettings::setFcPosTx(qint32 fc_pos_tx) {
    this->fc_pos_tx = fc_pos_tx;
    this->m_fc_pos_tx_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getTxBandwidth() {
    return tx_bandwidth;
}
void
SWGBladeRF2MIMOSettings::setTxBandwidth(qint32 tx_bandwidth) {
    this->tx_bandwidth = tx_bandwidth;
    this->m_tx_bandwidth_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getTx0GlobalGain() {
    return tx0_global_gain;
}
void
SWGBladeRF2MIMOSettings::setTx0GlobalGain(qint32 tx0_global_gain) {
    this->tx0_global_gain = tx0_global_gain;
    this->m_tx0_global_gain_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getTx1GlobalGain() {
    return tx1_global_gain;
}
void
SWGBladeRF2MIMOSettings::setTx1GlobalGain(qint32 tx1_global_gain) {
    this->tx1_global_gain = tx1_global_gain;
    this->m_tx1_global_gain_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getTxBiasTee() {
    return tx_bias_tee;
}
void
SWGBladeRF2MIMOSettings::setTxBiasTee(qint32 tx_bias_tee) {
    this->tx_bias_tee = tx_bias_tee;
    this->m_tx_bias_tee_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getTxTransverterMode() {
    return tx_transverter_mode;
}
void
SWGBladeRF2MIMOSettings::setTxTransverterMode(qint32 tx_transverter_mode) {
    this->tx_transverter_mode = tx_transverter_mode;
    this->m_tx_transverter_mode_isSet = true;
}

qint64
SWGBladeRF2MIMOSettings::getTxTransverterDeltaFrequency() {
    return tx_transverter_delta_frequency;
}
void
SWGBladeRF2MIMOSettings::setTxTransverterDeltaFrequency(qint64 tx_transverter_delta_frequency) {
    this->tx_transverter_delta_frequency = tx_transverter_delta_frequency;
    this->m_tx_transverter_delta_frequency_isSet = true;
}

QString*
SWGBladeRF2MIMOSettings::getFileRecordName() {
    return file_record_name;
}
void
SWGBladeRF2MIMOSettings::setFileRecordName(QString* file_record_name) {
    this->file_record_name = file_record_name;
    this->m_file_record_name_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGBladeRF2MIMOSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGBladeRF2MIMOSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGBladeRF2MIMOSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGBladeRF2MIMOSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGBladeRF2MIMOSettings::getReverseApiDeviceIndex() {
    return reverse_api_device_index;
}
void
SWGBladeRF2MIMOSettings::setReverseApiDeviceIndex(qint32 reverse_api_device_index) {
    this->reverse_api_device_index = reverse_api_device_index;
    this->m_reverse_api_device_index_isSet = true;
}


bool
SWGBladeRF2MIMOSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_dev_sample_rate_isSet){
            isObjectUpdated = true; break;
        }
        if(m_l_oppm_tenths_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx_center_frequency_isSet){
            isObjectUpdated = true; break;
        }
        if(m_log2_decim_isSet){
            isObjectUpdated = true; break;
        }
        if(m_fc_pos_rx_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx_bandwidth_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx0_gain_mode_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx0_global_gain_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx1_gain_mode_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx1_global_gain_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx_bias_tee_isSet){
            isObjectUpdated = true; break;
        }
        if(m_dc_block_isSet){
            isObjectUpdated = true; break;
        }
        if(m_iq_correction_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx_transverter_mode_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx_transverter_delta_frequency_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tx_center_frequency_isSet){
            isObjectUpdated = true; break;
        }
        if(m_log2_interp_isSet){
            isObjectUpdated = true; break;
        }
        if(m_fc_pos_tx_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tx_bandwidth_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tx0_global_gain_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tx1_global_gain_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tx_bias_tee_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tx_transverter_mode_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tx_transverter_delta_frequency_isSet){
            isObjectUpdated = true; break;
        }
        if(file_record_name && *file_record_name != QString("")){
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

