#include "main.h"

using namespace pros;

extern Controller master;
// Right side motor creation
extern Motor midRight;
// midRight.set_reversed(true);
extern Motor backRight;

// Right side motor group creation
extern Motor_Group rightSide;

// Left side motor creation
extern Motor midLeft;
// midLeft.set_reversed(true);
extern Motor backLeft;

// Left side motor group creation
extern Motor_Group leftSide;

// Sensor creation
extern IMU inertial;
extern Rotation hWheel;
extern Rotation vWheel;

extern Motor intake;
// Motor inLeft(inLeftMotor);

extern Motor cata;
extern Motor liftA;
extern Motor liftB;

extern ADIDigitalOut wingLeft;
extern ADIDigitalOut wingRight;
