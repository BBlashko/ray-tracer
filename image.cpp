#include "image.hpp"

#include <iostream>
#include <fstream>
#include <math.h>

Image::Image(int width, int height, int dpi)
{
    _width = width;
    _height = height;
    _dpi = dpi;

    _raster = new Color[_width * _height];
}

void Image::set_color(int x, int y, Color color)
{
    _raster[(_width * y) + x] = color;
}

void Image::save_image(const char* filename)
{
    //save a bitmap image.
    FILE *f;
    int k = _width * _height;
    int s = 4 * k;
    int filesize = 54 + s;

    double factor = 39.375;
    int m = static_cast<int>(factor);

    int ppm = _dpi * m;
    unsigned char bmpfileheader[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0 ,0};
    unsigned char bmpinfoheader[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};

    bmpfileheader[2] = (unsigned char) (filesize);
    bmpfileheader[3] = (unsigned char) (filesize >> 8);
    bmpfileheader[4] = (unsigned char) (filesize >> 16);
    bmpfileheader[5] = (unsigned char) (filesize >> 24);

    bmpinfoheader[4] = (unsigned char) (_width);
    bmpinfoheader[5] = (unsigned char) (_width >> 8);
    bmpinfoheader[6] = (unsigned char) (_width >> 16);
    bmpinfoheader[7] = (unsigned char) (_width >> 24);

    bmpinfoheader[8] = (unsigned char) (_height);
    bmpinfoheader[9] = (unsigned char) (_height >> 8);
    bmpinfoheader[10] = (unsigned char) (_height >> 16);
    bmpinfoheader[11] = (unsigned char) (_height >> 24);

    bmpinfoheader[21] = (unsigned char) (s);
    bmpinfoheader[22] = (unsigned char) (s >> 8);
    bmpinfoheader[23] = (unsigned char) (s >> 16);
    bmpinfoheader[24] = (unsigned char) (s >> 24);

    bmpinfoheader[25] = (unsigned char) (ppm);
    bmpinfoheader[26] = (unsigned char) (ppm >> 8);
    bmpinfoheader[27] = (unsigned char) (ppm >> 16);
    bmpinfoheader[28] = (unsigned char) (ppm >> 24);

    bmpinfoheader[29] = (unsigned char) (ppm);
    bmpinfoheader[30] = (unsigned char) (ppm >> 8);
    bmpinfoheader[31] = (unsigned char) (ppm >> 16);
    bmpinfoheader[32] = (unsigned char) (ppm >> 24);

    f = fopen(filename, "wb");
    fwrite (bmpfileheader, 1, 14, f);
    fwrite (bmpinfoheader, 1, 40, f);

    //pixel information
    for (int i = 0; i < k; i++)
    {
        Color rgb = _raster[i];

        double red = (rgb.red())*255;
        double green = (rgb.green())*255;
        double blue = (rgb.blue())*255;

        unsigned char color[3] = { (unsigned char) floor(blue), (unsigned char) floor(green), (unsigned char) floor(red) };
        fwrite(color, 1, 3, f);
    }

    fclose(f);
    std::string command = "imlib2_view ";
    command.append(filename);
    system(command.c_str());
}
