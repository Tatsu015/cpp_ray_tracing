#include <iostream>

#include "color.h"
#include "ray.h"

Color ray_color(const Ray &r)
{
    Vec3 unit_dir = unit_vector(r.dir_);
    double t = 0.5 * (unit_dir.y() + 1.0);
    return (1 - t) * Color(1, 1, 1) + t * Color(0.5, 0.7, 1);
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
            double u = i / (IMAGE_WIDTH - 1);
            double v = j / (IMAGE_HEIGHT - 1);
            Ray r(org, lower_left_corner + u * horizontal + v * vertical - org);
            Color pixcel_color = ray_color(r);
            write_color(std::cout, pixcel_color);
        }
    }

    std::cerr << "\nDone.\n";
    return 0;
}
