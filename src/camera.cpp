#include "camera.h"
#include "define.h"

Camera::Camera(const Point3 lookfrom, const Point3 lookat, const Vec3 vup, double vfov, const double aspect_ratio, const double aperture, const double focus_dist)
{
    const double theta = degrees_to_radians(vfov);
    const double h = tan(theta * 0.5);
    const double viewport_height = 2.0 * h;
    const double viewport_width = viewport_height * aspect_ratio;

    w_ = unit_vector(lookfrom - lookat);
    u_ = unit_vector(cross(vup, w_));
    v_ = cross(w_, u_);

    origin_ = lookfrom;
    horizontal_ = focus_dist * viewport_width * u_;
    vertical_ = focus_dist * viewport_height * v_;
    lower_left_corner_ = origin_ - horizontal_ / 2 - vertical_ / 2 - focus_dist * w_;

    lens_radius_ = aperture * 0.5;
}

Camera::~Camera()
{
}

Ray Camera::get_ray(const double s, const double t) const
{
    Vec3 random_disk = lens_radius_ * random_in_unit_disk();
    Vec3 offset = u_ * random_disk.x() + v_ * random_disk.y();

    return Ray(origin_ + offset, lower_left_corner_ + s * horizontal_ + t * vertical_ - origin_ - offset);
}
