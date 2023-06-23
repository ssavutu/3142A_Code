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

        // Drivetrain constructor
        Drivetrain(double wB, double tW, double wS, double iR, double sR, double sS){
            
                wheelSize = wS; // Size of tracking wheels
                trackWidth = tW; // Distance between the robot’s right wheels’ center point and the robot’s left wheels’ center point
                wheelBase = wB; // Distance between the drive shafts of the two drive wheels on the robot’s side
                inRPM = iR; // Input RPM of the drivetrain motors
                
                distH = sS; // Distance of the horizontal tracking wheel to the tracking center
                distV = sR; // Distance of the vertical tracking wheel to the tracking center

        }

        void position(){
                
        }

        void moveToPoint(double x, double y){
             
        }

        void moveToPose(double x, double y, double theta){

        }

        void angularPID(double setpoint){

        }

        void linearPID(double setpoint){

        }

};