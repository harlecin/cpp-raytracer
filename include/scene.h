#pragma once
#include <array>

struct Sphere {
    Sphere(std::array<double, 3> center, double radius, std::array<int, 3> color): _center(center), _radius(radius), _color(color) {};
    
    std::array<double, 3> _center;
    double _radius;
    std::array<int, 3> _color;
};