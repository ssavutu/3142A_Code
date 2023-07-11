#pragma once
/*
  pros::Motor motor_right (1);
  pros::Motor motor_left (2);
  pros::Motor_Group drive ({motor_right, motor_left});*/

class Drivetrain{
    public:

        double wheelSize;
        double trackWidth;
        double wheelBase;
        double inRPM;
        
        double distH;
        double distV;

        double theta;

        double gX;
        double gY;

        double h;
        double x1;
        double y1;
/*
        pros::Rotation hWheel;
        pros::Rotation vWheel;
      //  pros::Imu rot(1);

        pros::MotorGroup left;
        pros::MotorGroup right;
*/
/*
        pros::Controller master();
        pros::Motor left_mtr();
        pros::Motor right_mtr();
*/

        Drivetrain(double wS, double tW, double wB, double iR, double sR){};

        void position();

        void moveToPoint(double x, double y);

        void boomerang(double xEnd, double yEnd, double dLead, double thetaEnd){};

};

