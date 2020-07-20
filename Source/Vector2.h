#pragma once

class Vector2
{
public:
    Vector2() = default;
    Vector2(const int x, const int y);
    
    void rotateCCW();
    void rotateCW();

    Vector2 operator+(const Vector2& rhs) const;
    Vector2 operator*(const int s) const;
    const Vector2& operator+=(const Vector2& rhs);
    bool operator==(const Vector2& rhs) const;

    void setX(const int x) { mX = x; }
    int getX() const { return mX; }
    
    void setY(const int y) { mY = y; }
    int getY() const { return mY; }
    
private:
    int mX{};
    int mY{};
};
