#include <iostream>
#include <cmath>

#include "color.h"
#include "ray.h"
#include "define.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"
#include "mathutil.h"
#include "vec3.h"

Color ray_color(const Ray &r, const Hittable &world)
{
    const Color WHITE = Color(1, 1, 1);
    const Color LIGHT_BLUE = Color(0.5, 0.7, 1);

    HitRecord rec;
    if (world.hit(r, 0, INF, rec))
    {
        Point3 target = rec.p() + rec.normal() + random_in_unit_sphere();
        return 0.5 * ray_color(Ray(rec.p(), target - rec.p()), world);
    }

    Vec3 unit_dir = unit_vector(r.dir());
    double t = 0.5 * (unit_dir.y() + 1.0);
    Color gradation = (1 - t) * WHITE + t * LIGHT_BLUE;
    return gradation;
}

int main(int argc, char const *argv[])
{
    const int IMAGE_WIDTH = 384;
    const int IMAGE_HEIGHT = static_cast<int>(IMAGE_WIDTH / ASPECT_RATIO);
    const int SAMPLE_PER_PIXCEL = 100;

    Camera camera;

    std::cout << "P3\n"
              << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n"
              << "255\n";

    HittableList world;
    world.add(std::make_shared<Sphere>(Point3(0, 0, -1), 0.5));
    world.add(std::make_shared<Sphere>(Point3(0, -100.5, -1), 100));

    for (int j = IMAGE_HEIGHT - 1; j >= 0; --j)
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < IMAGE_WIDTH; ++i)
        {
            Color pixcel_color(0, 0, 0);
            for (int k = 0; k < SAMPLE_PER_PIXCEL; k++)
            {
                double u = (double(i) + random_double()) / (IMAGE_WIDTH - 1);
                double v = (double(j) + random_double()) / (IMAGE_HEIGHT - 1);
                Ray r = camera.get_ray(u, v);
                pixcel_color += ray_color(r, world);
            }
            write_color(std::cout, pixcel_color, SAMPLE_PER_PIXCEL);
        }
    }

    std::cerr << "\nDone.\n";
    return 0;
}
