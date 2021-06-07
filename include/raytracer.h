#pragma once

#include "canvas.h"
#include "camera.h"

class Raytracer {
    public:
        Raytracer();
    private:
        Canvas _canvas;
        Camera _camera;
};