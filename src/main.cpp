#include "main.h"
#include "robotconfig.h"


void screen() {
    // loop forever
    while (true) {
        lemlib::Pose pose = chassis.getPose(); // get the current position of the robot
        pros::lcd::print(0, "x: %f", pose.x); // print the x position
        pros::lcd::print(1, "y: %f", pose.y); // print the y position
        pros::lcd::print(2, "heading: %f", pose.theta); // print the heading
        pros::delay(10);
    }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	sylib::initialize();
	chassis.calibrate();
	chassis.setPose(0, 0, 0);
	chassis.setPose(5.2, 10.333, 87);
	pros::Task screenTask(screen); // create a task to print the position to the screen
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
	PTOEnabled = false;
	gearSwitch.set_value(PTOEnabled);
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	extension.set_value(true);
	right_PTO_motor.move(127);
	left_PTO_motor.move(127);
	pros::delay(115);
	Train::setVolt(95, 95);
	pros::delay(450);
	Train::setVolt(95, -95);
	pros::delay(100);
	Train::setVolt(127, 127);
	Intake::fwdspin();
	pros::delay(600);
	Train::setVolt(-127, -127);
	pros::delay(300);
	Train::setVolt(127, 127);
	pros::delay(600);
	Train::setVolt(-127, -127);
	pros::delay(300);
	Train::setVolt(127, 127);
	pros::delay(600);
	Train::setVolt(-127, -127);
	Intake::intstop();
	pros::delay(500);
	Train::setVolt(127, -127);
	pros::delay(125);
	Train::setVolt(0, 0);
	pros::delay(100);
	Train::setVolt(127, 127);
	Intake::revspin();
	pros::delay(900);
	Train::setVolt(0, 0);
	pros::delay(250);
	Intake::intstop();
	// Train::setVolt(-127, 127);
	// pros::delay(500);
	// Train::setVolt(127, 127);
	// pros::delay(600);
	// Intake::fwdspin();
	// pros::delay(250);
	// Intake::intstop();
	// Train::setVolt(0, 0);

	right_PTO_motor.move(-127);
	left_PTO_motor.move(-127);
	pros::delay(50);
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	lock.set_value(false);
	while (true) {
		Train::robotCentric();
		Intake::roll();
		Pneumatics::flap();
		PTO::PTOToggle();
		Pneumatics::extend();
		Pneumatics::spread();
		Ascend::lift();
		Shooter::shoot();

		pros::delay(20);
	}
}
