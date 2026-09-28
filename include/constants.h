#pragma once
#include "api.h"
#include "lemlib/api.hpp"
#include <array>

namespace constants{
    //motor ports negative for init reverse motion
    
    //drivetrain motors
    constexpr int rightMotorOne {11}; 
    constexpr int rightMotorTwo {-12};
    constexpr int rightMotorThree {13};
    constexpr int leftMotorOne {-1};
    constexpr int leftMotorTwo {2};
    constexpr int leftMotorThree {-3};

    //elevator motors
    constexpr int leftElevator {6};
    constexpr int rightElevator {-19};
    constexpr double maxMotorRotations {10};

    //fraction of maxMotorRotations for each major height: bottom, Y, X, A, top
    constexpr std::array<double, 5> elevatorMajorIncrements {0.0, 0.25, 0.5, 0.75, 1.0};
    constexpr int elevatorStepsPerSection {3}; 

    //elevator startup home (timed): drive down for a fixed time, then call that the bottom. only used on init
    //voltage to drive down with for both the startup home and the hold-B home, in volts (-12 to 12). negative = down
    constexpr double elevatorHomingVolts {-6.0};
    //how long to drive down, in ms. must be longer than a full drop from the top, plus a little margin
    constexpr int elevatorHomingTimeMs {1500};
    //B tap drives to encoder zero. within this many rotations of zero counts as "there"
    constexpr double elevatorZeroTolerance {0.5};
    //if zero isn't reached by this time, give up and unlock (hold B to re-home), in ms
    constexpr int elevatorReturnTimeoutMs {2000};
    //hold B longer than this to manually home (push down until released, zero on release), in ms
    constexpr int elevatorHoldToHomeMs {300};

    //elevator positioning
    //max speed for move_absolute, in rpm (green cartridge tops out at 200)
    constexpr int elevatorMoveVelocity {150};

    //misc
    constexpr int radio {8};
    constexpr int imu {10};

    //motor gear ratios 
    constexpr pros::v5::MotorGears drivetrainGearRatio {pros::v5::MotorGears::green};
    constexpr pros::v5::MotorGears elevatorGearRatio {pros::v5::MotorGears::green};

    inline pros::v5::Controller master({pros::E_CONTROLLER_MASTER});
    
    //lemlib::Drivetrain drivetrain {}
}