#ifndef VELUES_CACHE_H_
#define VELUES_CACHE_H_
#include <Arduino.h>
#include "SensorBase.h"

class ValuesCache : public SensorsValV {
    public:
    virtual sValue getFirst();
};


#endif