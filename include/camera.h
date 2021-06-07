#pragma once
#include <array>

class Camera {
    public:
        Camera(std::array<int, 3> position);
        std::array<int, 3> _position;
};