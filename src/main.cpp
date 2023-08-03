#include "main.h"
#include "movement.h"
#include <cmath>

// Right side motor creation
/**
 * A callback function for LLEMU's center button.s
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		//pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

	// Display Initialization
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
	pros::lcd::register_btn1_cb(on_center_button);

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
void competition_initialize() {}

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
void autonomous() {}

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
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor left_mtr(1);
	pros::Motor right_mtr(2);

	// Right Side Motors
	//frontRight 1
	const int midRightMotor = 2;
	const int backRightMotor = 3;

	// Left Side Motors
	//frontLeft 11
	const int midLeftMotor = 12;
	const int backLeftMotor = 13;

	// Intake Motors
	const int inRightMotor = 4;
	const int inLeftMotor = 14;

	// Sensors
	const int vWheelSensor = 5;
	const int hWheelSensor = 15;
	const int inertialSensor = 17;

	// Subsystems
	const int puncherMotor = 16;
	const int liftAMotor = 6;
	const int liftBMotor = 7;

	// Right side motor creation
	pros::Motor midRight(midRightMotor);
	pros::Motor backRight(backRightMotor);

	// Right side motor group creation
	pros::Motor_Group rightSide({midRight, backRight});

	// Left side motor creation
	pros::Motor midLeft(midLeftMotor);
	pros::Motor backLeft(backLeftMotor);

	// Left side motor group creation
	pros::Motor_Group leftSide({midLeft, backLeft});

	// Sensor creation
	pros::IMU inertial(inertialSensor);
	pros::Rotation hWheel(hWheelSensor);
	pros::Rotation vWheel(vWheelSensor);

	pros::Motor inRight(inRightMotor);
	pros::Motor inLeft(inLeftMotor);

	pros::Motor puncher(puncherMotor);
	pros::Motor liftA(liftAMotor);
	pros::Motor liftB(liftBMotor);
	
	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		int left = (pow(master.get_analog(ANALOG_LEFT_Y),3))/(pow(128,2));
		int right = (pow(master.get_analog(ANALOG_LEFT_X),3))/(pow(128,2));

		leftSide = left;
		rightSide = right;

		if(master.get_digital(DIGITAL_L1)){
			inLeft.move(127);
			inRight.move(127);
		}

		pros::delay(20);

	}
}
