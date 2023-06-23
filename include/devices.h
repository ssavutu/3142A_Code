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
pros::Motor midRight = pros::Motor(midRightMotor);
pros::Motor backRight = pros::Motor(backRightMotor);

// Right side motor group creation
pros::Motor_Group rightSide = pros::Motor_Group({midRight, backRight});

// Left side motor creation
pros::Motor midLeft = pros::Motor(midLeftMotor);
pros::Motor backLeft = pros::Motor(backLeftMotor);

// Left side motor group creation
pros::Motor_Group leftSide = pros::Motor_Group({midLeft, backLeft});

// Sensor creation
pros::IMU inertial = pros::IMU(inertial);
pros::Rotation hWheel = pros::Rotation(hWheelSensor);
pros::Rotation vWheel = pros::Rotation(vWheelSensor);

pros::Motor inRight = pros::Motor(inRightMotor);
pros::Motor inLeft = pros::Motor(inLeftMotor);

pros::Motor puncher = pros::Motor(puncherMotor);
pros::Motor liftA = pros::Motor(liftAMotor);
pros::Motor liftB = pros::Motor(liftBMotor);