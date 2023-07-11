#include "api.h"
#include "devices.h"

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

        // Drivetrain constructor
        Drivetrain(double wB, double tW, double wS, double iR, double tV, double tH){
            
                wheelSize = wS; // Size of tracking wheels
                trackWidth = tW; // Distance between the robot’s right wheels’ center point and the robot’s left wheels’ center point
                wheelBase = wB; // Distance between the drive shafts of the two drive wheels on the robot’s side
                inRPM = iR; // Input RPM of the drivetrain motors
                
                distH = tH; // Distance of the horizontal tracking wheel to the tracking center
                distV = tV; // Distance of the vertical tracking wheel to the tracking center
        }
        

        void position(){

                double posV;
                double posH;
                double prevPosV;
                double prevPosH;
                double deltaV;
                double deltaH;

                theta = inertial.get_heading();

                prevPosV = posV;
                prevPosH = posH;

                posV = vWheel.get_position();
                posH = hWheel.get_position();

                deltaV = (posV - prevPosV);
                deltaH = (posH - prevPosH);

                gY = (2*((deltaV/theta)+distV)*(sin(theta/2)) + gY);
                gX = (2*((deltaH/theta)+distH)*(sin(theta/2)) + gX);

        }

        void moveToPoint(double x, double y){

                //Turn PID
                double distA = sqrt((pow((gX - x), 2))+(pow((y - y), 2)));
                double distB = sqrt((pow((gX - gX), 2))+(pow((gY - y), 2)));
                double distC = sqrt((pow((gX - x), 2))+(pow((gY - y), 2)));
                
                double thetaNew = asin(distA*((sin(90))/distC));
                double oldTheta = theta;
                double error;

                while (theta < thetaNew){

                        error = thetaNew - theta;

                        double integral = integral + error;

                        if(error <= 0){

                                integral = 0;

                        }

                        double prevError;

                        double derivative = error - prevError;

                        prevError = error;

                        double power = (error*1) + (integral*1) + (derivative*1);

                        if (thetaNew > oldTheta){
                                rightSide = power;
                                leftSide = -power;
                        }

                        if (thetaNew > oldTheta){
                                rightSide = -power;
                                leftSide = power;
                        }
                        else{
                                rightSide = -power;
                                leftSide = power;
                        }

                        pros::delay(10);
                }

                // Drive PID
                double prevDist;
                double dist;
                
                while (dist > 1){

                        prevDist = dist;

                        dist = sqrt((pow((gX - x), 2))+(pow((gY - y), 2)));

                        double integral = integral + dist;

                        if (dist = 0){
                                integral = 0;
                        }

                        double derivative = dist - prevDist;

                        double  drivePower = (dist*1) + (integral*1) + (derivative*1);

                        rightSide = drivePower;
                        leftSide = drivePower;
                        pros::delay(10);
                }
        }

        void boomerang(double xEnd, double yEnd, double thetaEnd, double dLead){
        
        while (true)
                h = sqrt(pow((gX-xEnd), 2) + pow((gY-yEnd), 2));

                x1 = xEnd - h*(sin(thetaEnd))*dLead;

                y1 = yEnd - h*(cos(thetaEnd))*dLead;

                // Carrot Point = x1, y1

                //Pid with the speed tied to the end point but turning to the carrot point
        }

};