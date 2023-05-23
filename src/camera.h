#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"

class Camera
{
private:
    Point3 origin_;
    Vec3 horizontal_;
    Vec3 vertical_;
    Point3 lower_left_corner_;
    Vec3 u_;
    Vec3 v_;
    Vec3 w_;
    double lens_radius_;

public:
    Camera(const Point3 lookfrom, const Point3 lookat, const Vec3 vup, double vfov, const double aspect_ratio, const double aperture, const double focus_dist);
    ~Camera();

    Ray get_ray(const double s, const double t) const;
};

#endif