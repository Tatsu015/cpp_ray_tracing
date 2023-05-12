#ifndef VEC3_H
#define VEC3_H

#include <iostream>

class Vec3
{
public:
    double e_[3];

public:
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
    return Vec3(u.e_[0] - v.e_[0], u.e_[1] - v.e_[1], u.e_[2] - v.e_[2]);
}

inline Vec3 operator*(const double t, const Vec3 &v)
{
    return Vec3(v.e_[0] * t, v.e_[1] * t, v.e_[2] * t);
}

inline Vec3 operator*(const Vec3 &v, const double t)
{
    return Vec3(v.e_[0] * t, v.e_[1] * t, v.e_[2] * t);
}

inline Vec3 operator/(const Vec3 &v, const double t)
{
    return v * (1 / t);
}

inline double dot(const Vec3 &u, const Vec3 &v)
{
    return u.e_[0] * v.e_[0] +
           u.e_[1] * v.e_[1] +
           u.e_[2] * v.e_[2];
}

inline Vec3 cross(const Vec3 &u, const Vec3 &v)
{
    return Vec3(
        u.e_[1] * v.e_[2] - u.e_[2] * v.e_[1],
        u.e_[2] * v.e_[0] - u.e_[0] * v.e_[2],
        u.e_[0] * v.e_[1] - u.e_[1] * v.e_[0]);
}

inline Vec3 unit_vector(Vec3 v)
{
    return v / v.length();
}

using Point3 = Vec3;
using Color = Vec3;

#endif

/////////////////////

// #ifndef RAYTRACER_IN_ONE_WEEKEND_VEC3_HPP
// #define RAYTRACER_IN_ONE_WEEKEND_VEC3_HPP

// #include <math.h>
// #include <stdlib.h>
// #include <iostream>

// class Vec3
// {
// public:
//     Vec3() {}
//     Vec3(float e0, float e1, float e2)
//     {
//         e_[0] = e0;
//         e_[1] = e1;
//         e_[2] = e2;
//     }

//     inline float x() const { return e_[0]; }
//     inline float y() const { return e_[1]; }
//     inline float z() const { return e_[2]; }
//     inline float r() const { return e_[0]; }
//     inline float g() const { return e_[1]; }
//     inline float b() const { return e_[2]; }

//     inline const Vec3 &operator+() const { return *this; }
//     inline Vec3 operator-() const { return Vec3(-e_[0], -e_[1], -e_[2]); }
//     inline float operator[](int i) const { return e_[i]; }
//     inline float &operator[](int i) { return e_[i]; }

//     inline Vec3 &operator+=(const Vec3 &v2);
//     inline Vec3 &operator-=(const Vec3 &v2);
//     inline Vec3 &operator*=(const Vec3 &v2);
//     inline Vec3 &operator/=(const Vec3 &v2);
//     inline Vec3 &operator*=(float t);
//     inline Vec3 &operator/=(float t);

//     inline float length() const
//     {
//         return sqrt(e_[0] * e_[0] + e_[1] * e_[1] + e_[2] * e_[2]);
//     }
//     inline float squared_length() const
//     {
//         return e_[0] * e_[0] + e_[1] * e_[1] + e_[2] * e_[2];
//     }

//     inline void make_unit_vector();

//     float e_[3];
// };

// inline std::istream &operator>>(std::istream &is, Vec3 &t)
// {
//     is >> t.e_[0] >> t.e_[1] >> t.e_[2];
//     return is;
// }

// inline std::ostream &operator<<(std::ostream &os, const Vec3 &t)
// {
//     os << t.e_[0] << " " << t.e_[1] << " " << t.e_[2];
//     return os;
// }

// inline Vec3 operator+(const Vec3 &v1, const Vec3 &v2)
// {
//     return Vec3(v1.e_[0] + v2.e_[0], v1.e_[1] + v2.e_[1], v1.e_[2] + v2.e_[2]);
// }

// inline Vec3 operator-(const Vec3 &v1, const Vec3 &v2)
// {
//     return Vec3(v1.e_[0] - v2.e_[0], v1.e_[1] - v2.e_[1], v1.e_[2] - v2.e_[2]);
// }

// inline Vec3 operator*(const Vec3 &v1, const Vec3 &v2)
// {
//     return Vec3(v1.e_[0] * v2.e_[0], v1.e_[1] * v2.e_[1], v1.e_[2] * v2.e_[2]);
// }

// inline Vec3 operator/(const Vec3 &v1, const Vec3 &v2)
// {
//     return Vec3(v1.e_[0] / v2.e_[0], v1.e_[1] / v2.e_[1], v1.e_[2] / v2.e_[2]);
// }

// inline Vec3 operator*(float t, const Vec3 &v)
// {
//     return Vec3(v.e_[0] * t, v.e_[1] * t, v.e_[2] * t);
// }
// inline Vec3 operator*(const Vec3 &v, float t)
// {
//     return Vec3(v.e_[0] * t, v.e_[1] * t, v.e_[2] * t);
// }

// inline Vec3 operator/(const Vec3 &v, float t)
// {
//     return Vec3(v.e_[0] / t, v.e_[1] / t, v.e_[2] / t);
// }

// inline float dot(const Vec3 &v1, const Vec3 &v2)
// {
//     return v1.e_[0] * v2.e_[0] + v1.e_[1] * v2.e_[1] + v1.e_[2] * v2.e_[2];
// }

// inline Vec3 cross(const Vec3 &v1, const Vec3 &v2)
// {
//     return Vec3(
//         v1.e_[1] * v2.e_[2] - v1.e_[2] * v2.e_[1],
//         -(v1.e_[0] * v2.e_[2] - v1.e_[2] * v2.e_[0]),
//         v1.e_[0] * v2.e_[1] - v1.e_[1] * v2.e_[0]);
// }

// inline Vec3 &Vec3::operator+=(const Vec3 &v)
// {
//     e_[0] += v.e_[0];
//     e_[1] += v.e_[1];
//     e_[2] += v.e_[2];
//     return *this;
// }

// inline Vec3 &Vec3::operator-=(const Vec3 &v)
// {
//     e_[0] -= v.e_[0];
//     e_[1] -= v.e_[1];
//     e_[2] -= v.e_[2];
//     return *this;
// }

// inline Vec3 &Vec3::operator*=(const Vec3 &v)
// {
//     e_[0] *= v.e_[0];
//     e_[1] *= v.e_[1];
//     e_[2] *= v.e_[2];
//     return *this;
// }

// inline Vec3 &Vec3::operator/=(const Vec3 &v)
// {
//     e_[0] /= v.e_[0];
//     e_[1] /= v.e_[1];
//     e_[2] /= v.e_[2];
//     return *this;
// }

// inline Vec3 &Vec3::operator*=(float t)
// {
//     e_[0] *= t;
//     e_[1] *= t;
//     e_[2] *= t;
//     return *this;
// }

// inline Vec3 &Vec3::operator/=(float t)
// {
//     float k = 1.0 / t;
//     e_[0] *= k;
//     e_[1] *= k;
//     e_[2] *= k;
//     return *this;
// }

// inline Vec3 unit_vector(const Vec3 &v)
// {
//     return v / v.length();
// }

// inline void Vec3::make_unit_vector()
// {
//     float unit_scaler = 1.0 / length();
//     *this *= unit_scaler;
// }

// using Point3 = Vec3;
// using Color = Vec3;
// #endif // RAYTRACER_IN_ONE_WEEKEND_VEC3_HPP
