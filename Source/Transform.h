#pragma once

#include "Vector2.h"

class Transform
{
public:
    Transform(const Vector2& position, const Vector2& orientation);
    Transform(Vector2&& position, Vector2&& orientation);

    void translateForward(const int units);
    void rotateCCW();
    void rotateCW();

    bool operator==(const Transform& other) const;

    const Vector2& getPosition() const { return mPosition; }
    void setPosition(const Vector2& position) { mPosition = position; }

    const Vector2& getOrientation() const { return mOrientation; }
    void setOrientation(const Vector2& orientation) { mOrientation = orientation; }

private:
    Vector2 mPosition;
    Vector2 mOrientation;
};
