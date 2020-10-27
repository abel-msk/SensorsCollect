#ifndef SENSOR_COLLECTOR_H_
#define SENSOR_COLLECTOR_H_
#include <Arduino.h>
#include "SensorBase.h"

typedef std::vector<SensorBase*> SensorVector_p;

class SensorColelctor : private std::vector<SensorBase*> {
    private:
    SensorVector_p::iterator curIter;
    int curPosition=0;
    public:
    SensorColelctor();
    SensorBase* addSensor(SensorBase*);
    SensorColelctor& reset();
    SensorBase* getNext();
    SensorsValV* collect(SensorsValV *cache);
};

#endif