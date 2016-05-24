#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "ray.hpp"
#include "color.hpp"

struct RayResult
{
    double t;
    Vector3 normal;
    Color color;
};

class Object
{
public:
    virtual bool intersect(const Ray& ray, float tmin, float tmax, RayResult& result) const = 0;
};

#endif
