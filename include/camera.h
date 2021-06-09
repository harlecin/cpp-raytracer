#pragma once
#include <array>

class Camera {
    public:
        Camera(std::array<int, 3> position, int vw, int vh, int d);
        std::array<int, 3> _position;
        //Viewport size
        int _vw;
        int _vh;
        //Cam distance to viewport
        int _d;
        std::array<double, 3> canvas_to_viewport(int x, int y);
};