#include "vec3.h"
#include <cmath>

Vec3::Vec3() : e_{0, 0, 0}
{
}

Vec3::Vec3(double e0, double e1, double e2) : e_{e0, e1, e2}
{
}

Vec3::~Vec3()
{
}

double Vec3::x() const
{
    return e_[0];
}

double Vec3::y() const
{
    return e_[1];
}

double Vec3::z() const
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

Vec3 random_in_unit_sphere()
{
    while (true)
    {
        Vec3 p = Vec3::random(-1, 1);
        if (p.length_squared() >= 1)
        {
            continue;
        }
        return p;
    }
}

Vec3 random_in_unit_disk()
{
    while (true)
    {
        Vec3 p = Vec3(random_double(-1, 1), random_double(-1, 1), 0);
        if (p.length() < 1)
        {
            return p;
        }
    }
}

Vec3 random_unit_vector()
{
    double theta = random_double(0, 2 * PI);
    double z = random_double(-1, 1);
    double r = sqrt(1 - z * z);

    return Vec3(r * cos(theta), r * sin(theta), z);
}