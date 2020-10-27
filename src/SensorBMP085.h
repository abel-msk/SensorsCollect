#ifndef SENSOR_BMP085_H_
#define SENSOR_BMP085_H_
#include <SensorBase.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085.h>
#include <Arduino.h>

#define BMP085_ADDR 0x77

class SensorBMP085 : public SensorBase, public Adafruit_BMP085 {

    private:
    byte addr = BMP085_ADDR;
    SensorsValV*  lastValues;
    uint8_t mode = BMP085_ULTRAHIGHRES;

    sValue valT;
    sValue valP;
    TwoWire* i2cBus = nullptr;
    sensStat status = S_DIS;
    String descr = String("BMP085 sensor with I2C interface");
    String type = "I2C";
    String name = "BMP085";
    const char* sNameT ="BMP085/temperature";
    const char* sNameP = "BMP085/pressure";

    public:
    SensorBMP085();
    SensorBMP085& setMode(uint8_t mode);

    virtual SensorsValV* getValues(); 
    virtual void init(); 


    virtual sensStat getStatus() {return status;};
    virtual byte getAddr() {return addr;};
    virtual String getName() {return name;};
    virtual String getType() {return type;};
    virtual String getDescr() {return descr;};


};


#endif