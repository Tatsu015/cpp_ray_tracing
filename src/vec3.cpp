#include "vec3.h"
#include <cmath>

Vec3::Vec3(double e0, double e1, double e2) : e_{e0, e1, e2}
{
}

Vec3::~Vec3()
{
}

const double Vec3::x()
{
    return e_[0];
}

const double Vec3::y()
{
    return e_[1];
}

const double Vec3::z()
{
    return e_[2];
}

Vec3 Vec3::operator-() const
{
    return Vec3(-e_[0], -e_[1], -e_[2]);
}

double Vec3::operator[](int i) const
{
    return e_[i];
}

double &Vec3::operator[](int i)
{
    return e_[i];
}

Vec3 Vec3::operator+=(const Vec3 &v)
{
    e_[0] += v.e_[0];
    e_[1] += v.e_[1];
    e_[2] += v.e_[2];

    return *this;
}

Vec3 Vec3::operator*=(const double t)
{
    e_[0] *= t;
    e_[1] *= t;
    e_[2] *= t;

    return *this;
}

Vec3 Vec3::operator/=(const double t)
{
    e_[0] /= t;
    e_[1] /= t;
    e_[2] /= t;

    return *this;
}

double Vec3::length() const
{
    return sqrt(length_squared());
}

double Vec3::length_squared() const
{
    return e_[0] * e_[0] + e_[1] * e_[1] + e_[2] * e_[2];
}