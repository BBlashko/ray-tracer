#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "color.hpp"

class Image
{
public:
    Image(int width, int height, int dpi);
    void set_color(int x, int y, Color color);
    void save_image(const char* filename);

private:
    int _width;
    int _height;
    int _dpi;

    Color* _raster;
};

#endif
