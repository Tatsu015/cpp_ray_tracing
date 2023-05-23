#include <iostream>
#include <cmath>

#include "color.h"
#include "ray.h"
#include "define.h"
#include "hittable_list.h"
#include "Sphere.h"
#include "camera.h"
#include "mathutil.h"
#include "vec3.h"
#include "Lambertian.h"
#include "Metal.h"
#include "dielectric.h"

static const Color WHITE = Color(1, 1, 1);
static const Color LIGHT_BLUE = Color(0.5, 0.7, 1);

static const double ASPECT_RATIO = 16.0 / 9.0;
static const int IMAGE_WIDTH = 384;
static const int IMAGE_HEIGHT = static_cast<int>(IMAGE_WIDTH / ASPECT_RATIO);
static const int SAMPLE_PER_PIXCEL = 100;
static const int MAX_DEPTH = 50;

Color ray_color(const Ray &r, const Hittable &world, const int depth)
{
    // in too many reflective, set black color and return
    if (depth <= 0)
    {
        return Color(0, 0, 0);
    }

    HitRecord rec;
    if (world.hit(r, 0.001, INF, rec))
    {
        Color attenuation;
        Ray scattered;
        if (rec.material()->scatter(r, rec, attenuation, scattered))
        {
            return attenuation * ray_color(scattered, world, depth - 1);
        }
        return Color(0, 0, 0);
    }

    Vec3 unit_dir = unit_vector(r.dir());
    double t = 0.5 * (unit_dir.y() + 1.0);
    Color gradation = (1 - t) * WHITE + t * LIGHT_BLUE;
    return gradation;
}

HittableList random_scene()
{
    HittableList world;
    const int MATERIAL_SQRT_COUNT = 3;

    auto ground_material = std::make_shared<Lambertian>(Color(0.5, 0.5, 0.5));
    world.add(std::make_shared<Sphere>(Point3(0, -1000, 0), 1000, ground_material));

    for (int a = -MATERIAL_SQRT_COUNT; a < MATERIAL_SQRT_COUNT; a++)
    {
        for (int b = -MATERIAL_SQRT_COUNT; b < MATERIAL_SQRT_COUNT; b++)
        {
            auto choose_mat = random_double();
            Point3 center(a + 0.9 * random_double(), 0.2, b + 0.9 * random_double());

            if ((center - Vec3(4, 0.2, 0)).length() > 0.9)
            {
                std::shared_ptr<Material> Sphere_material;
                if (choose_mat < 0.8)
                {
                    // diffuse
                    auto albedo = Color::random() * Color::random();
                    Sphere_material = std::make_shared<Lambertian>(albedo);
                    world.add(std::make_shared<Sphere>(center, 0.2, Sphere_material));
                }
                else if (choose_mat < 0.95)
                {
                    // Metal
                    auto albedo = Color::random(0.5, 1);
                    auto fuzz = random_double(0, 0.5);
                    Sphere_material = std::make_shared<Metal>(albedo, fuzz);
                    world.add(std::make_shared<Sphere>(center, 0.2, Sphere_material));
                }
                else
                {
                    // glass
                    Sphere_material = std::make_shared<Dielectric>(1.5);
                    world.add(std::make_shared<Sphere>(center, 0.2, Sphere_material));
                }
            }
        }
    }

    auto material1 = std::make_shared<Dielectric>(1.5);
    world.add(std::make_shared<Sphere>(Point3(0, 1, 0), 1.0, material1));
    auto material2 = std::make_shared<Lambertian>(Color(0.4, 0.2, 0.1));
    world.add(std::make_shared<Sphere>(Point3(-4, 1, 0), 1.0, material2));
    auto material3 = std::make_shared<Metal>(Color(0.7, 0.6, 0.5), 0.0);
    world.add(std::make_shared<Sphere>(Point3(4, 1, 0), 1.0, material3));

    return world;
}

int main(int argc, char const *argv[])
{
    Point3 lookfrom(13, 2, 3);
    Point3 lookat(0, 0, 0);
    Vec3 vup(0, 1, 0);
    auto dist_to_focus = 10.0;
    auto aperture = 0.1;

    HittableList world = random_scene();

    Camera camera(lookfrom, lookat, vup, 20, ASPECT_RATIO, aperture, dist_to_focus);

    std::cout << "P3\n"
              << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n"
              << "255\n";

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
                pixcel_color += ray_color(r, world, MAX_DEPTH);
            }
            write_color(std::cout, pixcel_color, SAMPLE_PER_PIXCEL);
        }
    }

    std::cerr << "\nDone.\n";
    return 0;
}
