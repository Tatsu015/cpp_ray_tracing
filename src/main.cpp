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
    const int IMAGE_WIDTH = 256;
    const int IMAGE_HEIGHT = 256;

    std::cout << "P3\n"
              << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n"
              << "255\n";

    for (int j = IMAGE_HEIGHT - 1; j >= 0; --j)
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < IMAGE_WIDTH; ++i)
        {
            Color pixcel_color = Color(double(i) / (IMAGE_WIDTH - 1),
                                       double(j) / (IMAGE_HEIGHT - 1),
                                       0.25);
            write_color(std::cout, pixcel_color);
        }
    }

    std::cerr << "\nDone.\n";
    return 0;
}
