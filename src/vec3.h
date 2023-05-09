#ifndef VEC3_H
#define VEC3_H

#include <iostream>

class Vec3
{
public:
    double e_[3] = {0, 0, 0};

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
};

inline std::ostream &operator<<(std::ostream &out, const Vec3 &v)
{
    return out << v.e_[0] << ' ' << v.e_[1] << ' ' << v.e_[2];
}

inline Vec3 operator+(const Vec3 &u, const Vec3 &v)
{
    return Vec3(u.e_[0] + v.e_[0], u.e_[1] + v.e_[1], u.e_[2] + v.e_[2]);
}

inline Vec3 operator-(const Vec3 &u, const Vec3 &v)
{
    return Vec3(u.e_[0] - v.e_[0], u.e_[1] - v.e_[1], u.e_[2] - u.e_[2]);
}

inline Vec3 operator*(const double t, const Vec3 &v)
{
    return Vec3(v.e_[0] * t, v.e_[1] * t, v.e_[2] * t);
}

inline Vec3 operator*(const Vec3 &v, const double t)
{
    return v * t;
}

inline Vec3 operator/(const Vec3 &v, const double t)
{
    return v * (1 / t);
}

inline double dot(const Vec3 &u, const Vec3 &v)
{
    return u.e_[0] * v.e_[0] + u.e_[1] + v.e_[1] + u.e_[2] + v.e_[2];
}

inline Vec3 cross(const Vec3 &u, const Vec3 &v)
{
    return Vec3(
        u.e_[1] * v.e_[2] - u.e_[2] * v.e_[1],
        u.e_[2] * v.e_[0] - u.e_[0] * v.e_[2],
        u.e_[0] * v.e_[1] - u.e_[1] * v.e_[0]);
}

using Point3 = Vec3;
using Color = Vec3;

#endif
