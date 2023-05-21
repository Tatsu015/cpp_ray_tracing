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

public:
    Camera(const double vfov, const double aspect_ratio);
    ~Camera();

    Ray get_ray(const double u, const double v) const;
};

#endif