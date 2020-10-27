#include "SensorCollector.h"

bool collDebug = true;

SensorColelctor::SensorColelctor() {

}

SensorBase* SensorColelctor::addSensor(SensorBase* theSensor) {
    theSensor->init();
    push_back(theSensor);

    collDebug && Serial.print(String("Collector: Add sensotaddr 0x"));
    collDebug && Serial.print(theSensor->getAddr(),HEX);
    collDebug && Serial.print(". ");
    collDebug && Serial.println(theSensor->getDescr());

    return theSensor;
}

SensorColelctor& SensorColelctor::reset() {
    curPosition = 0;
    curIter = begin();
    return *this;
}

SensorBase* SensorColelctor::getNext() {
    SensorBase* curEl = NULL;
    if (size() > 0) {
        if (curPosition >= 0 ) {
            curEl = (*curIter);
            curIter++;
            curPosition++;
            if ( curIter == end()) {
                curPosition = -1;
            }
        }
    }
    return curEl;
}


SensorsValV* SensorColelctor::collect(SensorsValV* cache) {
    reset();
    SensorBase* sensor;
    while( (sensor = getNext() ) != NULL ) {
        //SensorsValV::iterator it;
        SensorsValV* sValueVector = sensor->getValues();
        if (sValueVector != NULL ) {
            cache->insert(std::end(*cache), std::begin(*sValueVector), std::end(*sValueVector));
        }
    }
    return cache;

}
