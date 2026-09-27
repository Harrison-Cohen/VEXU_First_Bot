#pragma once
#include "api.h"
#include "lemlib/api.hpp"

namespace constants{
    //motor ports negative for init reverse motion
    
    //drivetrain motors
    constexpr int rightMotorOne {-1}; 
    constexpr int rightMotorTwo {2};
    constexpr int rightMotorThree {-3};
    constexpr int leftMotorOne {11};
    constexpr int leftMotorTwo {-12};
    constexpr int leftMotorThree {13};

    //elevator motors
    constexpr int leftElevator {6};
    constexpr int rightElevator {-19};

    //misc
    constexpr int radio {8};
    constexpr int imu {10};

    //motor gear ratios 
    constexpr pros::v5::MotorGears drivetrainGearRatio {pros::v5::MotorGears::green};
    constexpr pros::v5::MotorGears elevatorGearRatio {pros::v5::MotorGears::green};

    inline pros::v5::Controller master({pros::E_CONTROLLER_MASTER});
    
    //lemlib::Drivetrain drivetrain {}
}