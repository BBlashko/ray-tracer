#ifndef Image_hpp
#define Image_hpp

#include <iostream>
#include <fstream>
#include "RGB.hpp"

class Image
{
public:
    Image();
    Image(int width, int height);
    Image(int width, int height, RGB background);
    bool set (int x, int y, const RGB& color);
    void writePPM(std::ofstream& outStream);
    // void readPPM();

    ~Image()
    {
        if (raster != NULL)
        {
            delete raster;
        }
    }
private:
    int x_;
    int y_;
    RGB** raster;
};
#endif
