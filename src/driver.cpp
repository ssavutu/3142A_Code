#include "main.h"


using namespace pros;

int left;
int right;
//test
void driveCurveArcade(){
    while (true){
        left = -((pow(master.get_analog(ANALOG_LEFT_Y), 3)) / (pow(128, 2)) + (pow(master.get_analog(ANALOG_RIGHT_X), 3)) / (pow(128, 2)));
        right = ((pow(master.get_analog(ANALOG_LEFT_Y), 3)) / (pow(128, 2)) - (pow(master.get_analog(ANALOG_RIGHT_X), 3)) / (pow(128, 2)));

        leftSide.move(left);
        rightSide.move(right);

        delay(20);
    }
}

void driveCurveTank(){
    while (true){
        left = (pow(master.get_analog(ANALOG_LEFT_Y),3))/(pow(128,2));
        right = -(pow(master.get_analog(ANALOG_RIGHT_Y),3))/(pow(128,2));

        leftSide.move(left);
        rightSide.move(right);

        delay(20);
    }
}

void subsystemControl(){
    while (true){
        if (master.get_digital(DIGITAL_L1)){
            intake.move(127);
        }

        if (master.get_digital(DIGITAL_R1)){

        }

        if (master.get_digital(DIGITAL_R2)){
            wingRight.set_value(true);
            wingLeft.set_value(true);
        }
        else{
            wingRight.set_value(false);
            wingLeft.set_value(false);
        }

        delay(20);
    }
}