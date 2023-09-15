#include "main.h"

using namespace pros;
Controller master (E_CONTROLLER_MASTER);
// Right side motor creation
Motor midRight(11, MOTOR_GEAR_600);
// midRight.set_reversed(true);
Motor backRight(12, MOTOR_GEAR_600);

// Right side motor group creation
Motor_Group rightSide({midRight, backRight});

// Left side motor creation
Motor midLeft(1, MOTOR_GEAR_600);
// midLeft.set_reversed(true);
Motor backLeft(2, MOTOR_GEAR_600);

// Left side motor group creation
Motor_Group leftSide({midLeft, backLeft});

// Sensor creation
IMU inertial(14);
Rotation hWheel(19);
Rotation vWheel(20);

Motor intake(6);
// Motor inLeft(inLeftMotor);

Motor cata(7, MOTOR_GEAR_100);
Motor liftA(8);
Motor liftB(9);

ADIDigitalOut wingLeft('A');
ADIDigitalOut wingRight('B');