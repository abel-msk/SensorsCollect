#ifndef SENSOR_BASE_H_
#define SENSOR_BASE_H_
#include <Arduino.h>
#include <Wire.h>

class sValue {
    public:
    const char* path;
    float value;
    bool correct;
    unsigned long timestamp;
};
typedef std::vector<sValue> SensorsValV;

enum sensStat {
    S_OK = 1,
    S_IDLE,
    S_ERROR,
    S_DIS,
};

String getStrStatus(sensStat s);

class SensorBase {
    public:
    virtual String getName()=0;
    virtual String getType()=0;
    virtual String getDescr()=0;
    virtual byte getAddr()=0;
    virtual sensStat getStatus()=0;

    virtual SensorsValV* getValues()=0; 
    virtual void init()=0; 

};

#endif