#include "canvas.h"
#include "CImg.h"

using namespace cimg_library;

Canvas::Canvas(int x, int y) : _x(x), _y(y)
{
    //initialize image of dimension x, y with white bg
    _img = CImg<unsigned int>(x, y, 1, 3, 255);
}

std::array<int, 3> Canvas::clamp_colors(std::array<int, 3> rgb)
{

    //Make sure colors are inside range
    for (int i = 0; i <= 2; i++)
    {
        if (rgb[i] < 0)
        {
            rgb[i] = 0;
        }
        else if (rgb[i] > 255)
        {
            rgb[i] = 255;
        }
    }

    return rgb;
}

void Canvas::put_pixel(int x, int y, std::array<int, 3> rgb)
{

    auto rgb_clamped = clamp_colors(rgb);

    //Put pixel relative to center of canvas
    int s_x = this->_x / 2 + x;
    int s_y = this->_y / 2 - y;

    for (int i = 0; i <= 2; i++)
    {
        _img(s_x, s_y, 0, i) = rgb_clamped[i];
    }
}

void Canvas::display()
{
    
    _img.display("Simple Raytracer");
}
