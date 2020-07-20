#include "Vector2.h"

#include <utility>

Vector2::Vector2(const int x, const int y)
: mX{x}, mY{y}
{
}

void Vector2::rotateCCW()
{
    std::swap(mX, mY);
    mX = -mX;
}

void Vector2::rotateCW()
{
    std::swap(mX, mY);
    mY = -mY;
}

Vector2 Vector2::operator+(const Vector2& rhs) const
{
    return Vector2{mX + rhs.mX, mY + rhs.mY};
}

const Vector2& Vector2::operator+=(const Vector2& rhs)
{
    mX += rhs.mX;
    mY += rhs.mY;
    return *this;
}

Vector2 Vector2::operator*(const int s) const
{
    return Vector2{mX * s, mY * s};
}

bool Vector2::operator==(const Vector2& rhs) const
{
    return mX == rhs.mX && mY == rhs.mY;
}
