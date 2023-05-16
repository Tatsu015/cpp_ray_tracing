#ifndef VEC3_H
#define VEC3_H

#include <iostream>

class Vec3
{
private:
    double e_[3];

public:
    Vec3(double e0, double e1, double e2);
    ~Vec3();

    double x() const;
    double y() const;
    double z() const;

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
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

inline Vec3 operator+(const Vec3 &u, const Vec3 &v)
{
    return Vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}

inline Vec3 operator-(const Vec3 &u, const Vec3 &v)
{
    return Vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

inline Vec3 operator*(const double t, const Vec3 &v)
{
    return Vec3(v.x() * t, v.y() * t, v.z() * t);
}

inline Vec3 operator*(const Vec3 &v, const double t)
{
    return Vec3(v.x() * t, v.y() * t, v.z() * t);
}

inline Vec3 operator/(const Vec3 &v, const double t)
{
    return v * (1 / t);
}

inline double dot(const Vec3 &u, const Vec3 &v)
{
    return u.x() * v.x() +
           u.y() * v.y() +
           u.z() * v.z();
}

inline Vec3 cross(const Vec3 &u, const Vec3 &v)
{
    return Vec3(
        u.y() * v.z() - u.z() * v.y(),
        u.z() * v.x() - u.x() * v.z(),
        u.x() * v.y() - u.y() * v.x());
}

inline Vec3 unit_vector(Vec3 v)
{
    return v / v.length();
}

using Point3 = Vec3;
using Color = Vec3;

#endif
