#include "robotconfig.h"

bool isPressed = false;
bool flapOn = false;
void Pneumatics::flap() {
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
        if(!isPressed) {
            flapOn = !flapOn;
            isPressed = true;
        }
    }
    else {
        isPressed = false;
    }

    flaps.set_value(flapOn);
}

bool isExtensionPressed = false;
bool extensionOn = false;
void Pneumatics::extend() {
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
        if(!isExtensionPressed) {
            extensionOn = !extensionOn;
            isExtensionPressed = true;
        }
    }
    else {
        isExtensionPressed = false;
    }

    extension.set_value(extensionOn);
}

bool isAutonWingPressed = false;
bool autonWingOn = false;
void Pneumatics::spread() {
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
        if(!isAutonWingPressed) {
            autonWingOn = !autonWingOn;
            isAutonWingPressed = true;
        }
    }
    else {
        isAutonWingPressed = false;
    }

    autonWing.set_value(autonWingOn);
}