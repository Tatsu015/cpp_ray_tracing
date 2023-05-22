#ifndef ANGLE_H
#define ANGLE_H

#include <random>

#include "define.h"

inline double degrees_to_radians(double degrees)
{
    return degrees * PI / 180;
}

inline double clamp(const double x, const double min, const double max)
{
    if (x < min)
    {
        return min;
    }
    if (x > max)
    {
        return max;
    }
    return x;
}

inline double random_double()
{
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(const double min, const double max)
{
    return min + (max - min) * random_double();
}

#endif