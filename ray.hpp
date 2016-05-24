#ifndef RAY_HPP
#define RAY_HPP

#include "vector3.hpp"

class Ray
{
public:
    Ray() : _origin(Vector3(0,0,0)), _direction(Vector3(1,0,0)) {};
    Ray(const Vector3 origin, const Vector3 direction) : _origin(origin), _direction(direction) {};
    Ray(const Ray& r) { *this = r; };

    Vector3 origin() const { return _origin; };
    Vector3 direction() const { return _direction; };
    Vector3 point_at_parameter(float t) const { return _origin + t * _direction; };

private:
    Vector3 _origin;
    Vector3 _direction;
};
#endif
