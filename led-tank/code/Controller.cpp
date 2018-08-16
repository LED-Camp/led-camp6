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

<<<<<<< HEAD
=======
void Controller::setDir(int indirA, int indirB) {
    position->setDir(indirA, indirB);
}
>>>>>>> 8fde969b4b68ff34cb8f800ab3b89468f60f6319

void Controller::changeDriveMode(Mode mode, int voltage_level) {
    twinWheelDriver->changeDriveMode(mode, voltage_level, position);
}

float Controller::getRanging(void) {
    return rangingSensor->getRanging();
}
