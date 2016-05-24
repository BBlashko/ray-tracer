#include "plane.hpp"

bool Plane::intersect(const Ray& ray, float tmin, float tmax, RayResult& result) const
{
    float a = dotProduct(normal(), ray.direction());
    if (abs(a) > tmin)
    {
        float b = dotProduct(ray.origin() + (-(normal() * distance())), normal());
        float t = -1 * (b / a);
        if (t >= tmin && t <= tmax)
        {
            result.t = t;
            result.color = color();
            result.normal = normal();
            return true;
        }
    }

    return false;
}
