#pragma once

namespace drivetrain{
    enum class Mode
    {
        tank,
        customArcade,
        lemlibArcade
    };

    void tankDrive();

    void customArcadeDrive();

    void lemlibArcade();

    void userSwitchingModes();

    void drive();

    void init();
}