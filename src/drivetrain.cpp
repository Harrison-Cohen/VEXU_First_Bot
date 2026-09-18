#include "drivetrain.h"
#include "constants.h"
#include "api.h"
#include <cmath>

namespace drivetrian{

    static pros::MotorGroup leftMotorGroup({constants::FLMotorPort, constants::BLMotorPort}, constants::drivetrainGearRatio);
    static pros::MotorGroup rightMotorGroup({constants::FRMotorPort, constants::BRMotorPort}, constants::drivetrainGearRatio);

    static pros::v5::Controller master({pros::E_CONTROLLER_MASTER});

    void tankDrive(){
        //left side of bot
        leftMotorGroup.move(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));

        //right side of bot
        rightMotorGroup.move(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
    }

    //blend movements into one stick
    void arcadeDrive(){
        double multiplier {1};
        
        //take in the stick vlaue for each stick and blend them
        //not using brace initalization b/c of warnings thrown
        double leftSum = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) + master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        double rightSum = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) - master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        //handels wrapping by dividing by same multiple to maintin users intended input for each movement 
        if(leftSum > 127 || leftSum < -127){
            multiplier = std::abs(127/leftSum);
        }
        else if(rightSum > 127 || rightSum < -127){
            multiplier = std::abs(127/rightSum);
        }

        //takes the sum of the cordinates for each sides of the stick and handels wrapping 
        leftMotorGroup.move(std::round(leftSum * multiplier));

        rightMotorGroup.move(std::round(rightSum * multiplier));
    }

    bool userSwitchingModes(bool currentMode){
        if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X) == 1){
            return !currentMode;
        }
        return currentMode;
    }
}