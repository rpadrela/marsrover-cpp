#include "MarsRoverController.h"
#include "MarsRover.h"

MarsRoverController::MarsRoverController(const std::shared_ptr<MarsRover>& rover)
: mRover{rover}
{
    mActions['L'] = &MarsRover::rotateLeft;
    mActions['R'] = &MarsRover::rotateRight;
    mActions['M'] = &MarsRover::move;
}

void MarsRoverController::move(const std::string& commands)
{
    for (const char command : commands)
        mActions[command](*mRover);
}
