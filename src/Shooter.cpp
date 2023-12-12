#include "robotconfig.h"

#include "pros/misc.h"






bool isPressedShoot = false;
bool ShootOn = false;
void Shooter::shoot() {
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
        if(!isPressedShoot) {
            ShootOn = !ShootOn;
            isPressedShoot = true;
        }
    }
    else {
        isPressedShoot = false;
    }

    if(ShootOn) {
        flywheel.set_velocity_custom_controller(3100);
    }
    else {
        flywheel.set_velocity_custom_controller(0);
    }
}