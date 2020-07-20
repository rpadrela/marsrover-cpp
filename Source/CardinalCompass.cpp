
#include "CardinalCompass.h"
#include "Vector2.h"

std::optional<Vector2> orientationFromCardinalDirection(const char direction)
{
    switch (direction)
    {
        case 'N':
            return Vector2{0,1};
        case 'E':
            return Vector2{1,0};
        case 'S':
            return Vector2{0,-1};
        case 'W':
            return Vector2{-1,0};
        default:
            return std::nullopt;
    }
}
