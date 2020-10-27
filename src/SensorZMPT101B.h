#ifndef SENSOR_ZMPT101B_H_
#define SENSOR_ZMPT101B_H_
#include <Arduino.h>
#include "SensorBase.h"
#include <Filters.h>

class SensorZMPT101B : public SensorBase {
    private:
    RunningStatistics inputStats;
    float windowSize = 2;
    float intercept = 0;  // to be adjusted based on calibration testin
    float slope = 2.11;  
    int initTunePeriod =  3; //in sec
    String name = "ZMPT101B";
    const char *  sName = "ZMPT101B/voltage";
    String descr = "AC voltage sensor";
    String type = "ANALOG";
    byte   addr = 0;
    sensStat status = S_DIS;

    byte sensorCode = 0;
    int inputPin = -1;
    SensorsValV*  lastValues;
    sValue val;
    uint16_t getMaxValue();
    void refreshWindow(unsigned long period);

    public:
    SensorZMPT101B();
    SensorZMPT101B(uint8_t pin);
    SensorsValV* getValues(); 
    void init(); 
    SensorZMPT101B* setWinSize(float ws);

    virtual sensStat getStatus() {return status;};
    virtual byte getAddr() {return addr;};
    virtual String getName() {return name;};
    virtual String getType() {return type;};
    virtual String getDescr() {return descr;};

};

#endif
