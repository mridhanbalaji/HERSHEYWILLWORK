#include "robotconfig.h"

// bool driveEnabled() {
//     if(controllerX != 0 && controllerY != 0) {
//         return true;
//     }
//     return false;
// }

// bool driveEnabled() {
//     if(controllerX != 0 && controllerY != 0) {
//         return true;
//     }
//     return false;
// }

bool isPTOPressed = false;
bool PTOEnabled = false;
void PTO::PTOToggle() {
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
        if(!isPTOPressed) {
            PTOEnabled = !PTOEnabled;
            isPTOPressed = true;
        }
    }
    else {
        isPTOPressed = false;
    }
    gearSwitch.set_value(PTOEnabled);

    // if(driveEnabled() && )
}