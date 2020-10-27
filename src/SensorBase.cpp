#include "SensorBase.h"

String getStrStatus(sensStat s) {
    switch(s) {
        case S_OK:
            return "OK";
            break;
        case S_IDLE:
            return "IDLE";
            break;
        case S_ERROR:
            return "ERROR";
            break;    
        case S_DIS:
            return "DISABLE";
            break;   
    }
    return "Unknown";
};
