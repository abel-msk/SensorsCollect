//SensorZMPT101B
#include "SensorZMPT101B.h"


SensorZMPT101B::SensorZMPT101B() {
    inputPin = PIN_A0;
    lastValues = new SensorsValV();
    pinMode(inputPin,INPUT);
    //analogReference(DEFAULT);
}

SensorZMPT101B::SensorZMPT101B(uint8_t pin) {
    inputPin = pin;
    lastValues = new SensorsValV();
    pinMode(inputPin,INPUT);
}

void SensorZMPT101B::init() {
    inputStats.setWindowSecs(windowSize);
    refreshWindow(initTunePeriod * 1000);
    float testVal = inputStats.sigma()* slope + intercept;
    if (testVal > 0) {
        status = S_OK;
    }
}

SensorZMPT101B* SensorZMPT101B::setWinSize(float ws) {
    windowSize = ws;
    return this;
}


SensorsValV* SensorZMPT101B::getValues() {
    lastValues->clear();
    //val.path=name.c_str();
    val.path=sName;

    // Get amplitude (maximum - or peak value)
    // uint32_t mVal = getMaxValue();

    // Serial.println("Max Value: \t" + String(mVal));

    // // Get actual voltage (ADC voltage reference = 1.1V)
    // mVal = mVal * 1100/1023;
    // // Calculate the RMS value ( = peak/√2 )
    // mVal /= sqrt(2);


    refreshWindow(windowSize * 1000);

    val.value = inputStats.sigma()* slope + intercept;
    // Serial.print("non calibrated value: \t" +String(inputStats.sigma()) +  " ");
    // Serial.println("Voltage value: \t" + String(val.value));

    val.correct = true;
    val.timestamp = time(0);
    lastValues->push_back(val);
    return lastValues;
}




void SensorZMPT101B::refreshWindow(unsigned long period) {
    unsigned long startTime = millis(); 
    int count = 0;
    while ((unsigned long)(millis() - startTime) < period ) { //We calculate and display every 1s
        inputStats.input(analogRead(inputPin));       // log to Stats function
        count++;
        delay(2);
    }
    //Serial.println(" Read : " + String(count) + " times.");

}


uint16_t SensorZMPT101B::getMaxValue() {
  uint16_t max_v = 0;
  for(uint8_t i = 0; i < 100; i++) {
    //uint16_t r =  map(analogRead(inputPin), 0, 1023, 0, 255);
    uint16_t r =  analogRead(inputPin);  // read from analog channel 3 (A3)
    Serial.println("read: \t" + String(r));
    if(max_v < r) max_v = r;
    delayMicroseconds(200);
  }
  return max_v;
}



