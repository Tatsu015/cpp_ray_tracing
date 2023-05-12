#include <iostream>
#include <cmath>

#include "color.h"
#include "ray.h"

double hit_sphere(const Point3 &center, const double radius, const Ray &r)
{
    // the answer of 2 dimensional equation is the intersection of circle and line
    // D of this equation is a^2 - 4ac, so D =0 has 2 intersection.
    Vec3 oc = r.org_ - center;
    double a = dot(r.dir_, r.dir_);
    double b = dot(oc, r.dir_);
    double c = dot(oc, oc) - radius * radius;
    double disc = b * b - a * c;

    if (disc < 0)
    {
        return -1;
    }
    else
    {
        return (-b - sqrt(disc)) / a;
    }

    return (disc > 0);
}

Color ray_color(const Ray &r)
{
    Vec3 sphere_center = Vec3(0, 0, -1);
    double radius = 0.5;
    const Color RED = Color(1, 0, 0);
    const Color WHITE = Color(1, 1, 1);
    const Color LIGHT_BLUE = Color(0.5, 0.7, 1);

    double param = hit_sphere(sphere_center, radius, r);
    if (param > 0.0)
    {
        Vec3 n = unit_vector(r.at(param) - sphere_center);
        Color shade = 0.5 * Color(n.x() + 1, n.y() + 1, n.z() + 1);
        return shade;
    }

    Vec3 unit_dir = unit_vector(r.dir_);
    double t = 0.5 * (unit_dir.y() + 1.0);
    Color gradation = (1 - t) * WHITE + t * LIGHT_BLUE;
    return gradation;
}

int main(int argc, char const *argv[])
{
    const double aspect_ratio = 16.0 / 9.0;
    const int IMAGE_WIDTH = 384;
    const int IMAGE_HEIGHT = static_cast<int>(IMAGE_WIDTH / aspect_ratio);

    std::cout << "P3\n"
              << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n"
              << "255\n";

    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;

    Vec3 org = Vec3(0, 0, 0);
    Vec3 horizontal = Vec3(viewport_width, 0, 0);
    Vec3 vertical = Vec3(0, viewport_height, 0);
    Vec3 focal_org = Vec3(0, 0, -focal_length);
    Vec3 lower_left_corner = org - horizontal / 2 - vertical / 2 + focal_org;

    for (int j = IMAGE_HEIGHT - 1; j >= 0; --j)
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < IMAGE_WIDTH; ++i)
        {
            double u = double(i) / (IMAGE_WIDTH - 1);
            double v = double(j) / (IMAGE_HEIGHT - 1);
            Ray r(org, lower_left_corner + u * horizontal + v * vertical - org);
            Color pixcel_color = ray_color(r);
            write_color(std::cout, pixcel_color);
        }
    }

    std::cerr << "\nDone.\n";
    return 0;
}
