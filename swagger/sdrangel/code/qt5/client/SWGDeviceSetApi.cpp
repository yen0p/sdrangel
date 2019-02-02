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

#include "SWGDeviceSetApi.h"
#include "SWGHelpers.h"
#include "SWGModelFactory.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace SWGSDRangel {

SWGDeviceSetApi::SWGDeviceSetApi() {}

SWGDeviceSetApi::~SWGDeviceSetApi() {}

SWGDeviceSetApi::SWGDeviceSetApi(QString host, QString basePath) {
    this->host = host;
    this->basePath = basePath;
}

void
SWGDeviceSetApi::devicesetChannelDelete(qint32 device_set_index, qint32 channel_index) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/sdrangel/deviceset/{deviceSetIndex}/channel/{channelIndex}");

    QString device_set_indexPathParam("{"); device_set_indexPathParam.append("deviceSetIndex").append("}");
    fullPath.replace(device_set_indexPathParam, stringValue(device_set_index));
    QString channel_indexPathParam("{"); channel_indexPathParam.append("channelIndex").append("}");
    fullPath.replace(channel_indexPathParam, stringValue(channel_index));


    SWGHttpRequestWorker *worker = new SWGHttpRequestWorker();
    SWGHttpRequestInput input(fullPath, "DELETE");





    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &SWGHttpRequestWorker::on_execution_finished,
            this,
            &SWGDeviceSetApi::devicesetChannelDeleteCallback);

    worker->execute(&input);
}

void
SWGDeviceSetApi::devicesetChannelDeleteCallback(SWGHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }


    QString json(worker->response);
    SWGChannelSettings* output = static_cast<SWGChannelSettings*>(create(json, QString("SWGChannelSettings")));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit devicesetChannelDeleteSignal(output);
    } else {
        emit devicesetChannelDeleteSignalE(output, error_type, error_str);
        emit devicesetChannelDeleteSignalEFull(worker, error_type, error_str);
    }
}

void
SWGDeviceSetApi::devicesetChannelPost(qint32 device_set_index, SWGChannelSettings& body) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/sdrangel/deviceset/{deviceSetIndex}/channel");

    QString device_set_indexPathParam("{"); device_set_indexPathParam.append("deviceSetIndex").append("}");
    fullPath.replace(device_set_indexPathParam, stringValue(device_set_index));


    SWGHttpRequestWorker *worker = new SWGHttpRequestWorker();
    SWGHttpRequestInput input(fullPath, "POST");


    
    QString output = body.asJson();
    input.request_body.append(output);
    


    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &SWGHttpRequestWorker::on_execution_finished,
            this,
            &SWGDeviceSetApi::devicesetChannelPostCallback);

    worker->execute(&input);
}

void
SWGDeviceSetApi::devicesetChannelPostCallback(SWGHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }


    QString json(worker->response);
    SWGSuccessResponse* output = static_cast<SWGSuccessResponse*>(create(json, QString("SWGSuccessResponse")));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit devicesetChannelPostSignal(output);
    } else {
        emit devicesetChannelPostSignalE(output, error_type, error_str);
        emit devicesetChannelPostSignalEFull(worker, error_type, error_str);
    }
}

void
SWGDeviceSetApi::devicesetChannelReportGet(qint32 device_set_index, qint32 channel_index) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/sdrangel/deviceset/{deviceSetIndex}/channel/{channelIndex}/report");

    QString device_set_indexPathParam("{"); device_set_indexPathParam.append("deviceSetIndex").append("}");
    fullPath.replace(device_set_indexPathParam, stringValue(device_set_index));
    QString channel_indexPathParam("{"); channel_indexPathParam.append("channelIndex").append("}");
    fullPath.replace(channel_indexPathParam, stringValue(channel_index));


    SWGHttpRequestWorker *worker = new SWGHttpRequestWorker();
    SWGHttpRequestInput input(fullPath, "GET");





    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &SWGHttpRequestWorker::on_execution_finished,
            this,
            &SWGDeviceSetApi::devicesetChannelReportGetCallback);

    worker->execute(&input);
}

void
SWGDeviceSetApi::devicesetChannelReportGetCallback(SWGHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }


    QString json(worker->response);
    SWGChannelReport* output = static_cast<SWGChannelReport*>(create(json, QString("SWGChannelReport")));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit devicesetChannelReportGetSignal(output);
    } else {
        emit devicesetChannelReportGetSignalE(output, error_type, error_str);
        emit devicesetChannelReportGetSignalEFull(worker, error_type, error_str);
    }
}

void
SWGDeviceSetApi::devicesetChannelSettingsGet(qint32 device_set_index, qint32 channel_index) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/sdrangel/deviceset/{deviceSetIndex}/channel/{channelIndex}/settings");

    QString device_set_indexPathParam("{"); device_set_indexPathParam.append("deviceSetIndex").append("}");
    fullPath.replace(device_set_indexPathParam, stringValue(device_set_index));
    QString channel_indexPathParam("{"); channel_indexPathParam.append("channelIndex").append("}");
    fullPath.replace(channel_indexPathParam, stringValue(channel_index));


    SWGHttpRequestWorker *worker = new SWGHttpRequestWorker();
    SWGHttpRequestInput input(fullPath, "GET");





    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &SWGHttpRequestWorker::on_execution_finished,
            this,
            &SWGDeviceSetApi::devicesetChannelSettingsGetCallback);

    worker->execute(&input);
}

void
SWGDeviceSetApi::devicesetChannelSettingsGetCallback(SWGHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }


    QString json(worker->response);
    SWGChannelSettings* output = static_cast<SWGChannelSettings*>(create(json, QString("SWGChannelSettings")));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit devicesetChannelSettingsGetSignal(output);
    } else {
        emit devicesetChannelSettingsGetSignalE(output, error_type, error_str);
        emit devicesetChannelSettingsGetSignalEFull(worker, error_type, error_str);
    }
}

void
SWGDeviceSetApi::devicesetChannelSettingsPatch(qint32 device_set_index, qint32 channel_index, SWGChannelSettings& body) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/sdrangel/deviceset/{deviceSetIndex}/channel/{channelIndex}/settings");

    QString device_set_indexPathParam("{"); device_set_indexPathParam.append("deviceSetIndex").append("}");
    fullPath.replace(device_set_indexPathParam, stringValue(device_set_index));
    QString channel_indexPathParam("{"); channel_indexPathParam.append("channelIndex").append("}");
    fullPath.replace(channel_indexPathParam, stringValue(channel_index));


    SWGHttpRequestWorker *worker = new SWGHttpRequestWorker();
    SWGHttpRequestInput input(fullPath, "PATCH");


    
    QString output = body.asJson();
    input.request_body.append(output);
    


    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &SWGHttpRequestWorker::on_execution_finished,
            this,
            &SWGDeviceSetApi::devicesetChannelSettingsPatchCallback);

    worker->execute(&input);
}

void
SWGDeviceSetApi::devicesetChannelSettingsPatchCallback(SWGHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }


    QString json(worker->response);
    SWGChannelSettings* output = static_cast<SWGChannelSettings*>(create(json, QString("SWGChannelSettings")));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit devicesetChannelSettingsPatchSignal(output);
    } else {
        emit devicesetChannelSettingsPatchSignalE(output, error_type, error_str);
        emit devicesetChannelSettingsPatchSignalEFull(worker, error_type, error_str);
    }
}

void
SWGDeviceSetApi::devicesetChannelSettingsPut(qint32 device_set_index, qint32 channel_index, SWGChannelSettings& body) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/sdrangel/deviceset/{deviceSetIndex}/channel/{channelIndex}/settings");

    QString device_set_indexPathParam("{"); device_set_indexPathParam.append("deviceSetIndex").append("}");
    fullPath.replace(device_set_indexPathParam, stringValue(device_set_index));
    QString channel_indexPathParam("{"); channel_indexPathParam.append("channelIndex").append("}");
    fullPath.replace(channel_indexPathParam, stringValue(channel_index));


    SWGHttpRequestWorker *worker = new SWGHttpRequestWorker();
    SWGHttpRequestInput input(fullPath, "PUT");


    
    QString output = body.asJson();
    input.request_body.append(output);
    


    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &SWGHttpRequestWorker::on_execution_finished,
            this,
            &SWGDeviceSetApi::devicesetChannelSettingsPutCallback);

    worker->execute(&input);
}

void
SWGDeviceSetApi::devicesetChannelSettingsPutCallback(SWGHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }


    QString json(worker->response);
    SWGChannelSettings* output = static_cast<SWGChannelSettings*>(create(json, QString("SWGChannelSettings")));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit devicesetChannelSettingsPutSignal(output);
    } else {
        emit devicesetChannelSettingsPutSignalE(output, error_type, error_str);
        emit devicesetChannelSettingsPutSignalEFull(worker, error_type, error_str);
    }
}

void
SWGDeviceSetApi::devicesetChannelsReportGet(qint32 device_set_index) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/sdrangel/deviceset/{deviceSetIndex}/channels/report");

    QString device_set_indexPathParam("{"); device_set_indexPathParam.append("deviceSetIndex").append("}");
    fullPath.replace(device_set_indexPathParam, stringValue(device_set_index));


    SWGHttpRequestWorker *worker = new SWGHttpRequestWorker();
    SWGHttpRequestInput input(fullPath, "GET");





    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &SWGHttpRequestWorker::on_execution_finished,
            this,
            &SWGDeviceSetApi::devicesetChannelsReportGetCallback);

    worker->execute(&input);
}

void
SWGDeviceSetApi::devicesetChannelsReportGetCallback(SWGHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }


    QString json(worker->response);
    SWGChannelsDetail* output = static_cast<SWGChannelsDetail*>(create(json, QString("SWGChannelsDetail")));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit devicesetChannelsReportGetSignal(output);
    } else {
        emit devicesetChannelsReportGetSignalE(output, error_type, error_str);
        emit devicesetChannelsReportGetSignalEFull(worker, error_type, error_str);
    }
}

void
SWGDeviceSetApi::devicesetDevicePut(qint32 device_set_index, SWGDeviceListItem& body) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/sdrangel/deviceset/{deviceSetIndex}/device");

    QString device_set_indexPathParam("{"); device_set_indexPathParam.append("deviceSetIndex").append("}");
    fullPath.replace(device_set_indexPathParam, stringValue(device_set_index));


    SWGHttpRequestWorker *worker = new SWGHttpRequestWorker();
    SWGHttpRequestInput input(fullPath, "PUT");


    
    QString output = body.asJson();
    input.request_body.append(output);
    


    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &SWGHttpRequestWorker::on_execution_finished,
            this,
            &SWGDeviceSetApi::devicesetDevicePutCallback);

    worker->execute(&input);
}

void
SWGDeviceSetApi::devicesetDevicePutCallback(SWGHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }


    QString json(worker->response);
    SWGDeviceListItem* output = static_cast<SWGDeviceListItem*>(create(json, QString("SWGDeviceListItem")));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit devicesetDevicePutSignal(output);
    } else {
        emit devicesetDevicePutSignalE(output, error_type, error_str);
        emit devicesetDevicePutSignalEFull(worker, error_type, error_str);
    }
}

void
SWGDeviceSetApi::devicesetDeviceReportGet(qint32 device_set_index) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/sdrangel/deviceset/{deviceSetIndex}/device/report");

    QString device_set_indexPathParam("{"); device_set_indexPathParam.append("deviceSetIndex").append("}");
    fullPath.replace(device_set_indexPathParam, stringValue(device_set_index));


    SWGHttpRequestWorker *worker = new SWGHttpRequestWorker();
    SWGHttpRequestInput input(fullPath, "GET");





    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &SWGHttpRequestWorker::on_execution_finished,
            this,
            &SWGDeviceSetApi::devicesetDeviceReportGetCallback);

    worker->execute(&input);
}

void
SWGDeviceSetApi::devicesetDeviceReportGetCallback(SWGHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }


    QString json(worker->response);
    SWGDeviceReport* output = static_cast<SWGDeviceReport*>(create(json, QString("SWGDeviceReport")));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit devicesetDeviceReportGetSignal(output);
    } else {
        emit devicesetDeviceReportGetSignalE(output, error_type, error_str);
        emit devicesetDeviceReportGetSignalEFull(worker, error_type, error_str);
    }
}

void
SWGDeviceSetApi::devicesetDeviceRunDelete(qint32 device_set_index) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/sdrangel/deviceset/{deviceSetIndex}/device/run");

    QString device_set_indexPathParam("{"); device_set_indexPathParam.append("deviceSetIndex").append("}");
    fullPath.replace(device_set_indexPathParam, stringValue(device_set_index));


    SWGHttpRequestWorker *worker = new SWGHttpRequestWorker();
    SWGHttpRequestInput input(fullPath, "DELETE");





    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &SWGHttpRequestWorker::on_execution_finished,
            this,
            &SWGDeviceSetApi::devicesetDeviceRunDeleteCallback);

    worker->execute(&input);
}

void
SWGDeviceSetApi::devicesetDeviceRunDeleteCallback(SWGHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }


    QString json(worker->response);
    SWGDeviceState* output = static_cast<SWGDeviceState*>(create(json, QString("SWGDeviceState")));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit devicesetDeviceRunDeleteSignal(output);
    } else {
        emit devicesetDeviceRunDeleteSignalE(output, error_type, error_str);
        emit devicesetDeviceRunDeleteSignalEFull(worker, error_type, error_str);
    }
}

void
SWGDeviceSetApi::devicesetDeviceRunGet(qint32 device_set_index) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/sdrangel/deviceset/{deviceSetIndex}/device/run");

    QString device_set_indexPathParam("{"); device_set_indexPathParam.append("deviceSetIndex").append("}");
    fullPath.replace(device_set_indexPathParam, stringValue(device_set_index));


    SWGHttpRequestWorker *worker = new SWGHttpRequestWorker();
    SWGHttpRequestInput input(fullPath, "GET");





    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &SWGHttpRequestWorker::on_execution_finished,
            this,
            &SWGDeviceSetApi::devicesetDeviceRunGetCallback);

    worker->execute(&input);
}

void
SWGDeviceSetApi::devicesetDeviceRunGetCallback(SWGHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }


    QString json(worker->response);
    SWGDeviceState* output = static_cast<SWGDeviceState*>(create(json, QString("SWGDeviceState")));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit devicesetDeviceRunGetSignal(output);
    } else {
        emit devicesetDeviceRunGetSignalE(output, error_type, error_str);
        emit devicesetDeviceRunGetSignalEFull(worker, error_type, error_str);
    }
}

void
SWGDeviceSetApi::devicesetDeviceRunPost(qint32 device_set_index) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/sdrangel/deviceset/{deviceSetIndex}/device/run");

    QString device_set_indexPathParam("{"); device_set_indexPathParam.append("deviceSetIndex").append("}");
    fullPath.replace(device_set_indexPathParam, stringValue(device_set_index));


    SWGHttpRequestWorker *worker = new SWGHttpRequestWorker();
    SWGHttpRequestInput input(fullPath, "POST");





    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &SWGHttpRequestWorker::on_execution_finished,
            this,
            &SWGDeviceSetApi::devicesetDeviceRunPostCallback);

    worker->execute(&input);
}

void
SWGDeviceSetApi::devicesetDeviceRunPostCallback(SWGHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }


    QString json(worker->response);
    SWGDeviceState* output = static_cast<SWGDeviceState*>(create(json, QString("SWGDeviceState")));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit devicesetDeviceRunPostSignal(output);
    } else {
        emit devicesetDeviceRunPostSignalE(output, error_type, error_str);
        emit devicesetDeviceRunPostSignalEFull(worker, error_type, error_str);
    }
}

void
SWGDeviceSetApi::devicesetDeviceSettingsGet(qint32 device_set_index) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/sdrangel/deviceset/{deviceSetIndex}/device/settings");

    QString device_set_indexPathParam("{"); device_set_indexPathParam.append("deviceSetIndex").append("}");
    fullPath.replace(device_set_indexPathParam, stringValue(device_set_index));


    SWGHttpRequestWorker *worker = new SWGHttpRequestWorker();
    SWGHttpRequestInput input(fullPath, "GET");





    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &SWGHttpRequestWorker::on_execution_finished,
            this,
            &SWGDeviceSetApi::devicesetDeviceSettingsGetCallback);

    worker->execute(&input);
}

void
SWGDeviceSetApi::devicesetDeviceSettingsGetCallback(SWGHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }


    QString json(worker->response);
    SWGDeviceSettings* output = static_cast<SWGDeviceSettings*>(create(json, QString("SWGDeviceSettings")));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit devicesetDeviceSettingsGetSignal(output);
    } else {
        emit devicesetDeviceSettingsGetSignalE(output, error_type, error_str);
        emit devicesetDeviceSettingsGetSignalEFull(worker, error_type, error_str);
    }
}

void
SWGDeviceSetApi::devicesetDeviceSettingsPatch(qint32 device_set_index, SWGDeviceSettings& body) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/sdrangel/deviceset/{deviceSetIndex}/device/settings");

    QString device_set_indexPathParam("{"); device_set_indexPathParam.append("deviceSetIndex").append("}");
    fullPath.replace(device_set_indexPathParam, stringValue(device_set_index));


    SWGHttpRequestWorker *worker = new SWGHttpRequestWorker();
    SWGHttpRequestInput input(fullPath, "PATCH");


    
    QString output = body.asJson();
    input.request_body.append(output);
    


    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &SWGHttpRequestWorker::on_execution_finished,
            this,
            &SWGDeviceSetApi::devicesetDeviceSettingsPatchCallback);

    worker->execute(&input);
}

void
SWGDeviceSetApi::devicesetDeviceSettingsPatchCallback(SWGHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }


    QString json(worker->response);
    SWGDeviceSettings* output = static_cast<SWGDeviceSettings*>(create(json, QString("SWGDeviceSettings")));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit devicesetDeviceSettingsPatchSignal(output);
    } else {
        emit devicesetDeviceSettingsPatchSignalE(output, error_type, error_str);
        emit devicesetDeviceSettingsPatchSignalEFull(worker, error_type, error_str);
    }
}

void
SWGDeviceSetApi::devicesetDeviceSettingsPut(qint32 device_set_index, SWGDeviceSettings& body) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/sdrangel/deviceset/{deviceSetIndex}/device/settings");

    QString device_set_indexPathParam("{"); device_set_indexPathParam.append("deviceSetIndex").append("}");
    fullPath.replace(device_set_indexPathParam, stringValue(device_set_index));


    SWGHttpRequestWorker *worker = new SWGHttpRequestWorker();
    SWGHttpRequestInput input(fullPath, "PUT");


    
    QString output = body.asJson();
    input.request_body.append(output);
    


    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &SWGHttpRequestWorker::on_execution_finished,
            this,
            &SWGDeviceSetApi::devicesetDeviceSettingsPutCallback);

    worker->execute(&input);
}

void
SWGDeviceSetApi::devicesetDeviceSettingsPutCallback(SWGHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }


    QString json(worker->response);
    SWGDeviceSettings* output = static_cast<SWGDeviceSettings*>(create(json, QString("SWGDeviceSettings")));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit devicesetDeviceSettingsPutSignal(output);
    } else {
        emit devicesetDeviceSettingsPutSignalE(output, error_type, error_str);
        emit devicesetDeviceSettingsPutSignalEFull(worker, error_type, error_str);
    }
}

void
SWGDeviceSetApi::devicesetFocusPatch(qint32 device_set_index) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/sdrangel/deviceset/{deviceSetIndex}/focus");

    QString device_set_indexPathParam("{"); device_set_indexPathParam.append("deviceSetIndex").append("}");
    fullPath.replace(device_set_indexPathParam, stringValue(device_set_index));


    SWGHttpRequestWorker *worker = new SWGHttpRequestWorker();
    SWGHttpRequestInput input(fullPath, "PATCH");





    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &SWGHttpRequestWorker::on_execution_finished,
            this,
            &SWGDeviceSetApi::devicesetFocusPatchCallback);

    worker->execute(&input);
}

void
SWGDeviceSetApi::devicesetFocusPatchCallback(SWGHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }


    QString json(worker->response);
    SWGSuccessResponse* output = static_cast<SWGSuccessResponse*>(create(json, QString("SWGSuccessResponse")));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit devicesetFocusPatchSignal(output);
    } else {
        emit devicesetFocusPatchSignalE(output, error_type, error_str);
        emit devicesetFocusPatchSignalEFull(worker, error_type, error_str);
    }
}

void
SWGDeviceSetApi::devicesetGet(qint32 device_set_index) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/sdrangel/deviceset/{deviceSetIndex}");

    QString device_set_indexPathParam("{"); device_set_indexPathParam.append("deviceSetIndex").append("}");
    fullPath.replace(device_set_indexPathParam, stringValue(device_set_index));


    SWGHttpRequestWorker *worker = new SWGHttpRequestWorker();
    SWGHttpRequestInput input(fullPath, "GET");





    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &SWGHttpRequestWorker::on_execution_finished,
            this,
            &SWGDeviceSetApi::devicesetGetCallback);

    worker->execute(&input);
}

void
SWGDeviceSetApi::devicesetGetCallback(SWGHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }


    QString json(worker->response);
    SWGDeviceSet* output = static_cast<SWGDeviceSet*>(create(json, QString("SWGDeviceSet")));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit devicesetGetSignal(output);
    } else {
        emit devicesetGetSignalE(output, error_type, error_str);
        emit devicesetGetSignalEFull(worker, error_type, error_str);
    }
}

void
SWGDeviceSetApi::instanceDeviceSetDelete() {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/sdrangel/deviceset");



    SWGHttpRequestWorker *worker = new SWGHttpRequestWorker();
    SWGHttpRequestInput input(fullPath, "DELETE");





    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &SWGHttpRequestWorker::on_execution_finished,
            this,
            &SWGDeviceSetApi::instanceDeviceSetDeleteCallback);

    worker->execute(&input);
}

void
SWGDeviceSetApi::instanceDeviceSetDeleteCallback(SWGHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }


    QString json(worker->response);
    SWGSuccessResponse* output = static_cast<SWGSuccessResponse*>(create(json, QString("SWGSuccessResponse")));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit instanceDeviceSetDeleteSignal(output);
    } else {
        emit instanceDeviceSetDeleteSignalE(output, error_type, error_str);
        emit instanceDeviceSetDeleteSignalEFull(worker, error_type, error_str);
    }
}

void
SWGDeviceSetApi::instanceDeviceSetPost(qint32 tx) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/sdrangel/deviceset");


    if (fullPath.indexOf("?") > 0)
      fullPath.append("&");
    else
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("tx"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(tx)));


    SWGHttpRequestWorker *worker = new SWGHttpRequestWorker();
    SWGHttpRequestInput input(fullPath, "POST");





    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &SWGHttpRequestWorker::on_execution_finished,
            this,
            &SWGDeviceSetApi::instanceDeviceSetPostCallback);

    worker->execute(&input);
}

void
SWGDeviceSetApi::instanceDeviceSetPostCallback(SWGHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }


    QString json(worker->response);
    SWGSuccessResponse* output = static_cast<SWGSuccessResponse*>(create(json, QString("SWGSuccessResponse")));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit instanceDeviceSetPostSignal(output);
    } else {
        emit instanceDeviceSetPostSignalE(output, error_type, error_str);
        emit instanceDeviceSetPostSignalEFull(worker, error_type, error_str);
    }
}


}
