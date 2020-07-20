#include "MarsRover.h"
#include "Vector2.h"

#include <utility>

MarsRover::MarsRover(const Transform& transform)
: mTransform{transform}
{
}

MarsRover::MarsRover(Transform&& transform)
: mTransform{std::move(transform)}
{
}

void MarsRover::move()
{
    mTransform.translateForward(1);
}

void MarsRover::rotateLeft()
{
    mTransform.rotateCCW();
}

void MarsRover::rotateRight()
{
    mTransform.rotateCW();
}
