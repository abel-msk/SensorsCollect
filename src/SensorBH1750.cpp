#include "SensorBH1750.h"
// #include <sys/time.h>
// #include <time.h>
//#include <lwip/apps/sntp.h>

SensorBH1750::SensorBH1750(byte a):BH1750::BH1750(a) {
    addr = a;
    lastValues = new SensorsValV();
    init();
};

SensorBH1750& SensorBH1750::setMode(Mode m) {
    mode = m;
    configure(mode);
    return *this;
}

SensorBH1750& SensorBH1750::setI2CBus(TwoWire* i2c) {
    i2cBus = i2c;
    return *this;
}

void SensorBH1750::init() {
    if ( begin(mode,addr,i2cBus) ) {
        status = S_OK;
    }
    else {
        status = S_ERROR;
    }
}

SensorsValV*  SensorBH1750::getValues() {

    if ( status == S_OK) {
        //Serial.println("SensorBH1750: Collect values");
        lastValues->clear();
        val.path=sName;
        
        if ( getStatus()) {
            val.value =  readLightLevel();  // lx
            val.correct = true;
        } else {
            val.value = 0;  // lx
            val.correct = false;
        }
        //if (  sntp_enabled() == 0) {
            val.timestamp = time(0);
        //    }
        // else { 
        //     val.timestamp = 0;}
            
        lastValues->push_back(val);
    }
    return lastValues;
}
