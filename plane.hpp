#ifndef Plane_hpp
#define Plane_hpp

#include "object.hpp"
#include "vector3.hpp"
#include "color.hpp"
#include <math.h>

class Plane : public Object
{
public:
    Plane(Vector3 normal, float distance, Color color) : _normal(normal), _distance(distance), _color(color) {};

    ~Plane() {};

    const Vector3& normal() const { return _normal; };
    Vector3& normal() { return _normal; };

    const float& distance() const { return _distance; };
    float& distance() { return _distance; };

    const Color& color() const { return _color; };
    Color& color() { return _color; };

    virtual bool intersect(const Ray& ray, float tmin, float tmax, RayResult& result) const;

private:
    Vector3 _normal;
    float _distance;
    Color _color;
};

#endif
