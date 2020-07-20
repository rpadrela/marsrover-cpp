#include "catch.hpp"

#include "MarsRover.h"
#include "MarsRoverController.h"
#include "CardinalCompass.h"

class MoveMarsRoverWithCommands
{
public:
    void setup(Transform&& start)
    {
        mRover = std::make_unique<MarsRover>(std::move(start));
    }

    void move(const std::string& commands)
    {
        MarsRoverController controller{mRover};
        controller.move(commands);
    }

public:
    std::shared_ptr<MarsRover> mRover;
};

TEST_CASE_METHOD(MoveMarsRoverWithCommands, "Move Mars Rover 1")
{
    const Vector2 north{*orientationFromCardinalDirection('N')};
    
    setup(Transform{Vector2{1,2}, north});
    move("LMLMLMLMM");
    REQUIRE(mRover->getTransform() == Transform{Vector2{1,3}, north});
}

TEST_CASE_METHOD(MoveMarsRoverWithCommands, "Move Mars Rover 2")
{
    const Vector2 east{*orientationFromCardinalDirection('E')};
    
    setup(Transform{Vector2{3,3}, east});
    move({"MMRMMRMRRM"});
    REQUIRE(mRover->getTransform() == Transform{Vector2{5,1}, east});
}
