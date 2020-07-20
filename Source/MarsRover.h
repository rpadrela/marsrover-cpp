#pragma once

#include "Transform.h"

class MarsRover
{
public:
    MarsRover(const Transform& transform);
    MarsRover(Transform&& transform);

    void move();
    void rotateLeft();
    void rotateRight();

    const Transform& getTransform() const { return mTransform; }
    
private:
    Transform mTransform;
};
