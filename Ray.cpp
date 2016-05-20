#include "Ray.hpp"

std::ostream& operator<<(std::ostream& outStream, const Ray& r)
{
    outStream << "(" << r.origin() << "), (" << r.direction() << ")";
    return outStream;
}
