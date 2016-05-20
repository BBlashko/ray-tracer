#include "Sphere.hpp"

bool Sphere::hit(const Ray& ray)
{
    Vector3 temp = ray.origin() - center();

    double a = dotProduct(ray.direction(), ray.direction());
    double b = 2*dotProduct(ray.direction(), temp);
    double c = dotProduct(temp, temp) - radius()*radius();

    double discriminant = b*b - 4*a*c;

    if(discriminant > 0)
    {
        return true;
    }
    return false;
}
