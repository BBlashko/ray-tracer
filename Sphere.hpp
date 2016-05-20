#ifndef Sphere_hpp
#define Sphere_hpp

#include "Vector3.hpp"
#include "RGB.hpp"
#include "Ray.hpp"
// #include "Object.hpp"

class Sphere
{
public:
    Sphere() {};
    Sphere(const Vector3& v, float radius, const RGB& color) : center_(v), radius_(radius), color_(color) {};

    // // The copy constructor.
    // Sphere(const Sphere& s)
    // {
    //     center_ = s.center_;
    //     radius_ = s.radius_;
    //     color_ = s.color_;
    // };

    // // The move constructor
    // Sphere(Sphere&& s)
    // {
    //     center_ = s.center_;
    //     radius_ = s.radius_;
    //     color_ = s.color_;
    // };

    ~Sphere() {};

    // // The copy assignment operator.
    // Sphere operator=(const Sphere& s)
    // {
    //     if (this != &s)
    //     {
    //         center_ = s.center_;
    //         radius_ = s.radius_;
    //         color_ = s.color_;
    //     }
    //     return *this;
    // };
    //
    // // The move assignment operator.
    // Sphere& operator=(Sphere&& s)
    // {
    //     center_ = s.center_;
    //     radius_ = s.radius_;
    //     color_ = s.color_;
    //     return *this;
    // };

    const Vector3& center() const { return center_; };
    Vector3& center() { return center_; };

    const float& radius() const { return radius_; };
    float& radius() { return radius_; };

    const RGB& color() const { return color_; };
    RGB& color() { return color_; };
    bool hit(const Ray& ray);

private:
    Vector3 center_;
    float radius_;
    RGB color_;
};
#endif
