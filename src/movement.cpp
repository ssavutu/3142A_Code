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

                //need to work on

                double deltaV;
                double deltaH;

                theta = inertial.get_heading();

                deltaV = vWheel.get_position();
                deltaH = hWheel.get_position();

                gY = 2*((deltaV/theta)+distV)*(sin(theta/2));
                gX = 2*((deltaH/theta)+distH)*(sin(theta/2));

        }

        void moveToPoint(double x, double y){

                //Turn PID
                double distA = sqrt((pow((gX - x), 2))+(pow((y - y), 2)));
                double distB = sqrt((pow((gX - gX), 2))+(pow((gY - y), 2)));
                double distC = sqrt((pow((gX - x), 2))+(pow((gY - y), 2)));
                
                double thetaNew = asin(distA*((sin(90))/distC));

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

                        pros::delay(10);
                }

                // Drive PID
                double prevDist;
                double dist;
                
                while (dist > 1){

                        double dist = sqrt((pow((gX - x), 2))+(pow((gY - y), 2)));

                        double integral = integral + dist;

                        if (dist = 0){
                                integral = 0;
                        }

                        double derivative = dist - prevDist;

                        prevDist = dist;

                        double  power = (dist*1) + (integral*1) + (derivative*1);

                        pros::delay(10);
                }
        }

        void moveToPose(double x, double y, double theta){

        }


};