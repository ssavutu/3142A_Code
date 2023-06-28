#pragma once

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