#include "raytracer.h"
#include "canvas.h"
#include <array>

std::array<double, 3> canvas_to_viewport(int x, int y, int vw, int vh, int d, int Cw, int Ch) {
    return std::array<double, 3> {1.0*x*vw/Cw, 1.0*y*vh/Ch, 1.0*d};
}


//Raytracer::Raytracer(Canvas canvas, Camera camera) {
//    this->_camera = camera;
//    this->_canvas = canvas;
//}