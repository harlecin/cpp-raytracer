#include "raytracer.h"
#include "canvas.h"
#include "scene.h"
#include <array>
#include <climits>

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
    double closest_sphere;

    return std::array<double, 3>{0, 0, 0};
    //for (auto sphere : scene)
    //{
    //    std::array<double, 2> t = intersect_ray_sphere();
    //}
}

//Raytracer::Raytracer(Canvas canvas, Camera camera) {
//    this->_camera = camera;
//    this->_canvas = canvas;
//}