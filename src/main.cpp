#include "canvas.h"
#include "camera.h"
#include "scene.h"
#include "raytracer.h"
#include <iostream>
#include <array>
#include <climits>

int main() {
    int Cw = 640;
    int Ch = 640;
    std::array<double, 3> O = {0, 0, 0};
    int vw = 1;
    int vh = 1;
    int d = 1;
    int t_min = 1;
    int t_max = INT_MAX;

    Sphere sphere1({0, -1, 3}, 1, {255, 0, 0});
    Sphere sphere2({2, 0, 4}, 1, {0, 0, 255});
    Sphere sphere3({-2, 0, 4}, 1, {0, 255, 0});

    auto scene = std::vector<Sphere>{sphere1, sphere2, sphere3};

    Canvas canvas(Cw, Ch);
    Camera camera(O, vw, vh, d);
    
    for(int x = -Cw/2; x <= Cw/2;x++) {
        for(int y = -Ch/2; y <= Ch/2;y++) {
            auto D = canvas_to_viewport(x, y, vw, vh, d, Cw, Ch);
            auto color = trace_ray(scene, O, D, t_min, t_max);
            canvas.put_pixel(x, y, color);
        }
    }
    canvas.display();

    return 0;
}