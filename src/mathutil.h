#ifndef ANGLE_H
#define ANGLE_H

#include <random>

#include "define.h"

inline double degree_to_radians(double degress)
{
    return degress / PI * 180;
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
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

#endif