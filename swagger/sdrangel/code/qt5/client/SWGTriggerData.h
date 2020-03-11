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

/*
 * SWGTriggerData.h
 *
 * see GLScopeSettings::TriggerData
 */

#ifndef SWGTriggerData_H_
#define SWGTriggerData_H_

#include <QJsonObject>



#include "SWGObject.h"
#include "export.h"

namespace SWGSDRangel {

class SWG_API SWGTriggerData: public SWGObject {
public:
    SWGTriggerData();
    SWGTriggerData(QString* json);
    virtual ~SWGTriggerData();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGTriggerData* fromJson(QString &jsonString) override;

    qint32 getProjectionType();
    void setProjectionType(qint32 projection_type);

    qint32 getInputIndex();
    void setInputIndex(qint32 input_index);

    float getTriggerLevel();
    void setTriggerLevel(float trigger_level);

    qint32 getTriggerLevelCoarse();
    void setTriggerLevelCoarse(qint32 trigger_level_coarse);

    qint32 getTriggerLevelFine();
    void setTriggerLevelFine(qint32 trigger_level_fine);

    qint32 getTriggerPositiveEdge();
    void setTriggerPositiveEdge(qint32 trigger_positive_edge);

    qint32 getTriggerBothEdges();
    void setTriggerBothEdges(qint32 trigger_both_edges);

    qint32 getTriggerHoldoff();
    void setTriggerHoldoff(qint32 trigger_holdoff);

    qint32 getTriggerDelay();
    void setTriggerDelay(qint32 trigger_delay);

    float getTriggerDelayMult();
    void setTriggerDelayMult(float trigger_delay_mult);

    qint32 getTriggerDelayCoarse();
    void setTriggerDelayCoarse(qint32 trigger_delay_coarse);

    qint32 getTriggerDelayFine();
    void setTriggerDelayFine(qint32 trigger_delay_fine);

    qint32 getTriggerRepeat();
    void setTriggerRepeat(qint32 trigger_repeat);

    qint32 getTriggerColor();
    void setTriggerColor(qint32 trigger_color);

    float getTriggerColorR();
    void setTriggerColorR(float trigger_color_r);

    float getTriggerColorG();
    void setTriggerColorG(float trigger_color_g);

    float getTriggerColorB();
    void setTriggerColorB(float trigger_color_b);


    virtual bool isSet() override;

private:
    qint32 projection_type;
    bool m_projection_type_isSet;

    qint32 input_index;
    bool m_input_index_isSet;

    float trigger_level;
    bool m_trigger_level_isSet;

    qint32 trigger_level_coarse;
    bool m_trigger_level_coarse_isSet;

    qint32 trigger_level_fine;
    bool m_trigger_level_fine_isSet;

    qint32 trigger_positive_edge;
    bool m_trigger_positive_edge_isSet;

    qint32 trigger_both_edges;
    bool m_trigger_both_edges_isSet;

    qint32 trigger_holdoff;
    bool m_trigger_holdoff_isSet;

    qint32 trigger_delay;
    bool m_trigger_delay_isSet;

    float trigger_delay_mult;
    bool m_trigger_delay_mult_isSet;

    qint32 trigger_delay_coarse;
    bool m_trigger_delay_coarse_isSet;

    qint32 trigger_delay_fine;
    bool m_trigger_delay_fine_isSet;

    qint32 trigger_repeat;
    bool m_trigger_repeat_isSet;

    qint32 trigger_color;
    bool m_trigger_color_isSet;

    float trigger_color_r;
    bool m_trigger_color_r_isSet;

    float trigger_color_g;
    bool m_trigger_color_g_isSet;

    float trigger_color_b;
    bool m_trigger_color_b_isSet;

};

}

#endif /* SWGTriggerData_H_ */
