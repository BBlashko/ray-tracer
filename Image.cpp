#include "Image.hpp"

Image::Image() {};

Image::Image(int width, int height)
{
    x_ = width;
    y_ = height;

    raster = new RGB*[x_];
    for (int i = 0; i < x_; i++)
    {
        raster[i] = new RGB[y_];
    }
}

Image::Image(int width, int height, RGB color)
{
    x_ = width;
    y_ = height;

    raster = new RGB*[x_];
    for (int i = 0; i < x_; i++)
    {
        raster[i] = new RGB[y_];
    }

    for (int i = 0; i < x_; i++)
    {
        for (int j = 0; j < y_; j++)
        {
            raster[i][j] = color;
        }
    }
}

bool Image::set (int x, int y, const RGB& color)
{
    if (x < 0 || x > x_) { return false; }
    if (y < 0 || y > y_) { return false; }
    raster[x][y] = color;
    return true;
}

void Image::writePPM(std::ofstream& outStream)
{
    outStream << "P6\n" << x_ << " " << y_ << "\n255\n";
    unsigned char r, g, b;
    for (int i = 0; i < x_; i++)
    {
        for (int j = 0; j < y_; j++)
        {
            r = static_cast<unsigned char>(std::min(1.f, raster[i][j].r()) * 255);
            g = static_cast<unsigned char>(std::min(1.f, raster[i][j].g()) * 255);
            b = static_cast<unsigned char>(std::min(1.f, raster[i][j].b()) * 255);
            outStream << r << g << b;
        }
    }
}
// void readPPM();
