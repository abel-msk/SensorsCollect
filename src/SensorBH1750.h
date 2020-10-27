#ifndef SENSOR_BH1750_H_
#define SENSOR_BH1750_H_
#include <SensorBase.h>
#include <Adafruit_Sensor.h>
#include <BH1750.h>

#define BH1750_ADDR 0x23

class SensorBH1750 : public SensorBase, public BH1750 {
    private:
    byte addr = BH1750_ADDR;
    SensorsValV*  lastValues;
    sValue val;
    Mode mode = BH1750::CONTINUOUS_HIGH_RES_MODE;
    TwoWire* i2cBus = nullptr;
    sensStat status = S_DIS;
    String descr = String("BH1750 light meter sensor with I2C interface.");
    String name = "BH1750";
    String type = "I2C";
    const char* sName = "BH1750/illumination";

    public:

    SensorBH1750(byte addr = 0x23);
    SensorBH1750& setMode(Mode mode);
    SensorBH1750& setI2CBus(TwoWire* i2c);

    virtual SensorsValV* getValues(); 
    virtual void init(); 

    virtual sensStat getStatus() {return status;};
    virtual byte getAddr() {return addr;};
    virtual String getName() {return name;};
    virtual String getType() {return type;};
    virtual String getDescr() {return descr;};
};


#endif