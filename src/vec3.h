#ifndef VEC3_H
#define VEC3_H

#include <iostream>

class Vec3
{
private:
    double e_[3];

public:
    Vec3();
    Vec3(double e0, double e1, double e2);
    ~Vec3();

    const double x();
    const double y();
    const double z();

    Vec3 operator-() const;
    double operator[](int i) const;
    double &operator[](int i);
    Vec3 operator+=(const Vec3 &v);
    Vec3 operator*=(const double t);
    Vec3 operator/=(const double t);
    double length() const;
    double length_squared() const;

    // inline std::iostream &operator<<(std::iostream &out, const Vec3 &v)
    // {
    //     return out << v.
    // }
};

using Point3 = Vec3;
using Color = Vec3;

#endif
