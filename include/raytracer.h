#pragma once

#include "canvas.h"
#include "camera.h"
#include "scene.h"
#include <vector>

std::array<double, 3> canvas_to_viewport(int x, int y, int vw, int vh, int d, int Cw, int Ch);

std::array<int, 3> trace_ray(std::vector<Sphere> scene, std::array<double, 3> O, std::array<double, 3> D, int t_min, int t_max);


class Raytracer {
    public:
        Raytracer(Canvas canvas, Camera camera);
    private:
        Canvas _canvas;
        Camera _camera;
};