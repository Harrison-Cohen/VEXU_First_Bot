#include "constants.h"
#include "api.h"
#include "endeffector.h"
#include "lemlib/api.hpp"
#include <cmath>

namespace endeffector{
    pros::Motor endEffector(10, pros::v5::MotorGears::green);

        void init(){
        endEffector.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        endEffector.brake();
    }
}


