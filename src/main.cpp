#include <iostream>

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
            double r = double(i) / (IMAGE_WIDTH - 1);
            double g = double(j) / (IMAGE_HEIGHT - 1);
            double b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << "\n";
        }
    }

    std::cerr << "\nDone.\n";
    return 0;
}
