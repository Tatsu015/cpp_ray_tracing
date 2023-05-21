#include "camera.h"
#include "define.h"

Camera::Camera(const double vfov, const double aspect_ratio)
{
    const double theta = degree_to_radians(vfov);
    const double h = tan(theta * 0.5);
    const double viewport_height = 2.0 * h;
    const double viewport_width = viewport_height * aspect_ratio;
    const double focal_length = 1.0;

    origin_ = Point3(0, 0, 0);
    horizontal_ = Vec3(viewport_width, 0, 0);
    vertical_ = Vec3(0, viewport_height, 0);
    lower_left_corner_ = origin_ - horizontal_ / 2 - vertical_ / 2 - Vec3(0, 0, focal_length);
}

Camera::~Camera()
{
}

Ray Camera::get_ray(const double u, const double v) const
{
    return Ray(origin_, lower_left_corner_ + u * horizontal_ + v * vertical_ - origin_);
}
