#ifndef __CONTROLLER__
#define __CONTROLLER__

#include <cstdint>
#include "RangingSensor.h"
#include "TwinWheelDriver.h"
#include "Position.h"

class Controller {
private:
    TwinWheelDriver *twinWheelDriver;
    Position *position;
    RangingSensor *rangingSensor;

protected:
    Controller(void);

public:
    static Controller* _instance;

    static Controller* getInstance(void);

    // Positionån
    void reset(void);
    void getPosition(float* distance, float* angle);
    void setDir(int indirA, int indirB);

    // twinWheelDriverån
    void changeDriveMode(Mode mode, int voltage_level);

    // RangingSensorån
    uint16_t getRanging(void);
};

#endif
