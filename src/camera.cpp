#include "camera.h"
#include "define.h"

static const double VIEWPORT_HEIGHT = 2.0;
static const double VIEWPORT_WIDTH = VIEWPORT_HEIGHT * ASPECT_RATIO;
static const double FOCAL_LENGTH = 1.0;

Camera::Camera() : origin_(Point3(0, 0, 0)),
                   horizontal_(Vec3(VIEWPORT_WIDTH, 0, 0)),
                   vertical_(Vec3(0, VIEWPORT_HEIGHT, 0)),
                   lower_left_corner_(origin_ - horizontal_ / 2 - vertical_ / 2 + Vec3(0, 0, -FOCAL_LENGTH))
{
}

Camera::~Camera()
{
}

Ray Camera::get_ray(const double u, const double v) const
{
    return Ray(origin_, lower_left_corner_ + u * horizontal_ + v * vertical_ - origin_);
}
