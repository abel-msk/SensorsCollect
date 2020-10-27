#include "SensorBMP085.h"
#include <sys/time.h>
#include <time.h>
//#include <lwip/apps/sntp.h>

SensorBMP085::SensorBMP085() {
    lastValues = new SensorsValV();
    init();

}

SensorBMP085& SensorBMP085::setMode(uint8_t m) {
    mode =m;
    return *this;
}

SensorsValV* SensorBMP085::getValues() {

    lastValues->clear();
    if ( status == S_OK ) {
        
        //Serial.println("SensorBMP085: Collect values");

        valT.path=sNameT;
        valP.path=sNameP;

        if ( getStatus()) {
            valT.value =  readTemperature();  // C
            valT.correct = true;
            valP.value =  readPressure();  // lx
            valP.correct = true;
        } else {
            valT.value = 0;  // lx
            valT.correct = false;
            valP.value = 0;  // lx
            valP.correct = false;
        }
        // if (sntp_enabled() == 0) {
            valT.timestamp = time(0);
            valP.timestamp = time(0);
        //}
        // else { 
        //     valT.timestamp = 0;
        //     valP.timestamp = 0;
        // }
        lastValues->push_back(valT);
        lastValues->push_back(valP);
    }
    return lastValues;
}

void SensorBMP085::init() {
    if ( begin(mode) ) {
        status = S_OK;
    }
    else {
        status = S_ERROR;
    }
}


