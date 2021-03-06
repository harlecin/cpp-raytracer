#pragma once
#include "CImg.h"
#include <array>

using namespace cimg_library;


class Canvas {
    public:
        Canvas(int Cw, int Ch);
        void put_pixel(int Cx, int Cy, std::array<int, 3> rgb);
        void display();
        int _Cw;
        int _Ch;
    private:
        CImg<unsigned int> _img;
        std::array<int, 3> clamp_colors(std::array<int, 3> rgb);
};

// TODO: Can I remove std::array and still use {} in function call somehow? https://stackoverflow.com/questions/29360555/c-passing-an-array-directly-into-a-function-without-initializing-it-first
// TODO: Add is_on_canvas() check to put_pixel()
// TODO: Does CImg return a pointer to the data?