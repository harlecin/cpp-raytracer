#include "camera.h"

Camera::Camera(std::array<int, 3> position, int vw, int vh, int d) : _position(position), _vw(vw), _vh(vh), _d(d) {}

std::array<double, 3> Camera::canvas_to_viewport(int x, int y) {
    std::array<double, 3> viewpoint;

    viewpoint[0] = 1.0*x/_vw;
}