#include "Image.hpp"
#include "RGB.hpp"
#include "Vector3.hpp"
#include "Sphere.hpp"
#include "Ray.hpp"

#include <iostream>
#include <fstream>
#include <cstdint>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    RGB backgroundColor = RGB(0, 0, 0);
    Image image = Image(500, 500, RGB(255, 255, 0));
    char* filename = argv[1];
    std::string command = "imlib2_view ";
    command.append(filename);

    Sphere sphere = Sphere(Vector3(250, 250, -10), 50, RGB (255, 0, 0));
    Sphere sphere1 = Sphere(Vector3(250, 400, -10), 20, RGB (255, 0, 0));

    for (int x = 0; x < 500; x++)
    {
        for (int y = 0; y < 500; y++)
        {
            Ray ray = Ray(Vector3(x, y, 0), Vector3(0, 0, -1));
            if (sphere1.hit(ray) || sphere.hit(ray))
            {
                image.set(x, y, RGB(255, 0, 0));
            }
            else
            {
                image.set(x, y, backgroundColor);
            }

        }
    }

    std::ofstream myfile;
    myfile.open(filename, std::ios::binary);
    image.writePPM(myfile);
    myfile.close();

    system(command.c_str());
}
