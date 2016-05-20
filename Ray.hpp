#ifndef Ray_hpp
#define Ray_hpp

#include "Vector3.hpp"

class Ray
{
public:
    Ray() {};
    Ray(const Vector3 a, const Vector3 b)
    {
        data[0] = a;
        data[1] = b;
    }

    Ray(const Ray& r) { *this = r; };

    Vector3 origin() const { return data[0]; };
    Vector3 direction() const { return data[1]; };

    Vector3 data[2];
};

std::ostream& operator<<(std::ostream& outStream, const Ray& v);

#endif
