#include "Transform.h"

#include <utility>

Transform::Transform(const Vector2& position, const Vector2& orientation)
: mPosition(position), mOrientation(orientation)
{
}

Transform::Transform(Vector2&& position, Vector2&& orientation)
: mPosition{std::move(position)}, mOrientation{std::move(orientation)}
{
}

bool Transform::operator==(const Transform& other) const
{
    return mPosition == other.mPosition && mOrientation == other.mOrientation;
}

void Transform::translateForward(const int units)
{
    mPosition += mOrientation * units;
}

void Transform::rotateCCW()
{
    mOrientation.rotateCCW();
}

void Transform::rotateCW()
{
    mOrientation.rotateCW();
}
