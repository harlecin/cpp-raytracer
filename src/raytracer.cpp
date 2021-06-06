#include "canvas.h"
#include <iostream>

int main() {
    
    Canvas canvas(640, 400);

    canvas.put_pixel(0, 0, {0, 0, 0}); 
    canvas.display();

    return 0;
}