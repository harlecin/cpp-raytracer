#include "raytracer.h"
#include "canvas.h"
#include "scene.h"
#include <array>
#include <climits>
#include <math.h>

std::array<double, 3> canvas_to_viewport(int x, int y, int vw, int vh, int d, int Cw, int Ch)
{
    return std::array<double, 3>{1.0 * x * vw / Cw, 1.0 * y * vh / Ch, 1.0 * d};
}

//TODO: finish!
std::array<double, 2> intersect_ray_sphere()
{
    return std::array<double, 2>{1, 2};
}

std::array<int, 3> trace_ray(std::vector<Sphere> scene, std::array<double, 3> O, std::array<double, 3> D, int t_min, int t_max)
{
    double closest_t = INT_MAX;
    Sphere closest_sphere({0, 0, 0}, 0, {0,0,0});

    for (auto sphere : scene)
    {
        std::array<double, 2> t = intersect_ray_sphere(O, D, sphere);
        if (t_min <= t[0] & t[0] < t_max & t[0] < closest_t) {
            closest_t = t[0];
            closest_sphere = sphere;
        }
        if (t_min <= t[1] & t[1] < t_max & t[1] < closest_t) {
            closest_t = t[2];
            closest_sphere = sphere;
        }
    }
    if (closest_sphere._radius == 0) {
        return std::array<int, 3>{0, 0, 0};
    }

    return closest_sphere._color;

}

std::array<double, 2> intersect_ray_sphere(std::array<double, 3> O, std::array<double, 3> D, Sphere sphere) {
    auto r = sphere._radius;
    std::array<double,3> CO = {
        O[0] - sphere._center[0],
        O[1] - sphere._center[1],
        O[2] - sphere._center[2],
    };

    double a = D[0]*D[0] + D[1]*D[1] + D[2]*D[2];
    double b = 2*(CO[0]*D[0] + CO[1]*D[1] + CO[2]*D[2]);
    double c = CO[0]*CO[0] + CO[1]*CO[1] + CO[2]*CO[2] - sphere._radius * sphere._radius;

    double discriminant = b*b - 4*a*c;
    if(discriminant < 0) {
        return std::array<double, 2> {INT_MAX, INT_MAX};
    }

    double t1 = (-b + sqrt(discriminant)/(2*a));
    double t2 = (-b - sqrt(discriminant)/(2*a));

    return std::array<double, 2> {t1, t2};
    
}