#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "MarsRover.h"
#include "CardinalCompass.h"

TEST_CASE( "Test creation" )
{
    const Transform start{Vector2{1,2}, *orientationFromCardinalDirection('S')};

    MarsRover rover{start};
    REQUIRE(rover.getTransform() == start);
}

TEST_CASE( "Test rotating left" )
{
    MarsRover rover{Transform{Vector2{}, *orientationFromCardinalDirection('N')}};
    rover.rotateLeft();
    REQUIRE(rover.getTransform() == Transform{Vector2{}, *orientationFromCardinalDirection('W')});
}

TEST_CASE( "Test rotating left full circle" )
{
    const Transform start{Vector2{}, *orientationFromCardinalDirection('N')};
    
    MarsRover rover{start};
    rover.rotateLeft();
    rover.rotateLeft();
    rover.rotateLeft();
    rover.rotateLeft();
    REQUIRE(rover.getTransform() == start);
}

TEST_CASE( "Test rotating right" )
{
    MarsRover rover{Transform{Vector2{}, *orientationFromCardinalDirection('N')}};
    rover.rotateRight();
    REQUIRE(rover.getTransform() == Transform{Vector2{}, *orientationFromCardinalDirection('E')});
}

TEST_CASE( "Test rotating right full circle" )
{
    const Transform start{Vector2{}, *orientationFromCardinalDirection('N')};
    
    MarsRover rover{start};
    rover.rotateRight();
    rover.rotateRight();
    rover.rotateRight();
    rover.rotateRight();
    REQUIRE(rover.getTransform() == start);
}

TEST_CASE( "Test moving forward" )
{
    MarsRover rover{Transform{Vector2{}, *orientationFromCardinalDirection('N')}};
    rover.move();
    REQUIRE(rover.getTransform() == Transform{Vector2{0, 1}, *orientationFromCardinalDirection('N')});
}

TEST_CASE( "Test moving to the left" )
{
    MarsRover rover{Transform{Vector2{1,0}, *orientationFromCardinalDirection('N')}};
    rover.rotateLeft();
    rover.move();
    REQUIRE(rover.getTransform() == Transform{Vector2{}, *orientationFromCardinalDirection('W')});
}

TEST_CASE( "Test moving to the right" )
{
    MarsRover rover{Transform{Vector2{}, *orientationFromCardinalDirection('N')}};
    rover.rotateRight();
    rover.move();
    REQUIRE(rover.getTransform() == Transform{Vector2{1,0}, *orientationFromCardinalDirection('E')});
}
