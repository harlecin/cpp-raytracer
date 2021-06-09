#pragma once

#include "canvas.h"
#include "camera.h"

std::array<double, 3> canvas_to_viewport(int x, int y, int vw, int vh, int d, int Cw, int Ch);

class Raytracer {
    public:
        Raytracer(Canvas canvas, Camera camera);
    private:
        Canvas _canvas;
        Camera _camera;
};