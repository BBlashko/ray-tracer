#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "object.hpp"
#include "vector3.hpp"
#include "ray.hpp"
#include "color.hpp"

class Sphere : public Object
{
public:
    Sphere(const Vector3& v, float radius, const Color& color) : center_(v), radius_(radius), color_(color) {};
    ~Sphere() {};

    const Vector3& center() const { return center_; };
    Vector3& center() { return center_; };

    const float& radius() const { return radius_; };
    float& radius() { return radius_; };

    const Color& color() const { return color_; };
    Color& color() { return color_; };

    virtual bool intersect(const Ray& ray, float tmin, float tmax, RayResult& result) const;

private:
    Vector3 center_;
    float radius_;
    Color color_;
};
#endif
