#include "ray.h"

Ray::Ray()
{
}

Ray::Ray(const Point3 &org, const Vec3 &dir) : org_(org), dir_(dir)
{
}

Ray::~Ray()
{
}

Point3 Ray::at(const double t) const
{
    return Point3(org_ + t * dir_);
}