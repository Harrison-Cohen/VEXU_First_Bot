#include "drivetrain.h"
#include "constants.h"
#include "api.h"
#include "lemlib/api.hpp"
#include <cmath>

namespace elevator{

    pros::MotorGroup elevatorMotors ({constants::leftElevator, constants::rightElevator}, constants::elevatorGearRatio);

    void manualCommand(){
        if(constants::master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) == 1){
            elevatorMotors.move(127);
        }
        else if(constants::master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) == 1){
            elevatorMotors.move(-127);
        }
        else{
            elevatorMotors.move(0);
        }
    }

    void setGeneralState(){

    }

    void addIncrement(){

    }

}