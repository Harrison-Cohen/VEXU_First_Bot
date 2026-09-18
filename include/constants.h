#pragma once
#include "api.h"

namespace constants{
    //motor ports negative for init reverse motion
    constexpr int FLMotorPort {-1}; 
    constexpr int FRMotorPort {2};
    constexpr int BLMotorPort {-3};
    constexpr int BRMotorPort {4};
    constexpr int IMUPort {5};

    //motor gear ratios 
    //idk what green is but tune to real ratio lol
    constexpr pros::v5::MotorGears drivetrainGearRatio {pros::v5::MotorGears::green};
    
    //controler ID
}