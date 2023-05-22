#include "camera.h"
#include "define.h"

Camera::Camera(const Point3 lookfrom, const Point3 lookat, const Vec3 vup, double vfov, const double aspect_ratio)
{
    const double theta = degrees_to_radians(vfov);
    const double h = tan(theta * 0.5);
    const double viewport_height = 2.0 * h;
    const double viewport_width = viewport_height * aspect_ratio;

    const Vec3 w = unit_vector(lookfrom - lookat);
    const Vec3 u = unit_vector(cross(vup, w));
    const Vec3 v = unit_vector(cross(w, u));

    origin_ = lookfrom;
    horizontal_ = viewport_width * u;
    vertical_ = viewport_height * v;
    lower_left_corner_ = origin_ - horizontal_ / 2 - vertical_ / 2 - w;
}

Camera::~Camera()
{
}

Ray Camera::get_ray(const double u, const double v) const
{
    return Ray(origin_, lower_left_corner_ + u * horizontal_ + v * vertical_ - origin_);
}
