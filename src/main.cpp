#include "canvas.h"
#include "camera.h"
#include "raytracer.h"
#include <iostream>
#include <array>

int main() {
    int Cw = 640;
    int Ch = 400;
    std::array<int, 3> position = {0, 0, 0};
    std::array<double, 3> D;
    int vw = Cw;
    int vh = Ch;
    int d = 5;


    Canvas canvas(Cw, Ch);
    Camera camera(position, vw, vh, d);
    
    for(int x = -Cw/2; x <= Cw/2;x++) {
        for(int y = -Ch/2; y <= Ch/2;y++) {
            D = canvas_to_viewport(x, y, vw, vh, d, Cw, Ch);
            std::array<int, 3> color = {0,0,0};
            canvas.put_pixel(x, y, color);
        }
    }
    canvas.display();

    return 0;
}