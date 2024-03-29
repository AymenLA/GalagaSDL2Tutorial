/**
 * @file MathHelper.h
 * @author
 * @brief Header file of public class MathHelper.
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <math.h>

#define PI 3.14159265
#define DEG_TO_RAD PI / 180.0f

struct Vector2 
{

    float x;
    float y;

    Vector2(float _x = 0.0f, float _y = 0.0f)
        : x(_x), y(_y) {}

    float MagnitudeSqr(void){

        return x*x + y*y;
    }

    float Magnitude(void){

        return (float)sqrt(x*x + y*y);
    }

    Vector2 Normalized(void){

        float mag = Magnitude();

        return Vector2(x / mag, y / mag);
    }
};


inline Vector2 operator+(const Vector2& lhs, const Vector2& rhs)
{
    return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}


inline Vector2 operator-(const Vector2& lhs, const Vector2& rhs)
{
    return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}


inline Vector2 RotateVector(Vector2& vec, float angle)
{
    float radAngle = (float)(angle*DEG_TO_RAD);

    return Vector2((float)(vec.x * cos(radAngle) - vec.y * sin(radAngle)), 
                   (float)(vec.x * sin(radAngle) + vec.y * cos(radAngle)));
}