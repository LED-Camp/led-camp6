#include "Controller.h"

Controller* Controller::_instance = 0;

Controller* Controller::getInstance(void) {
    if (_instance == 0) {
        _instance = new Controller();
    }

    return _instance;

}

Controller::Controller(void) {
    twinWheelDriver = TwinWheelDriver::getInstance(5, 6, 13, 19);
    position = Position::getInstance(17, 27);
    rangingSensor = RangingSensor::getInstance();
    rangingSensor->Initialize();
}

void Controller::reset(void) {
    position->reset();
}

void Controller::getPosition(float* distance, float* angle) {
    position->getPosition(distance, angle);
}


void Controller::changeDriveMode(Mode mode, int voltage_level) {
    twinWheelDriver->changeDriveMode(mode, voltage_level, position);
}

float Controller::getRanging(void) {
    return rangingSensor->getRanging();
}
