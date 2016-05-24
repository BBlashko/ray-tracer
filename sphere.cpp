#include "sphere.hpp"

bool Sphere::intersect(const Ray& ray, float tmin, float tmax, RayResult& result) const
{
    Vector3 temp = ray.origin() - center();
    double a = dotProduct(ray.direction(), ray.direction());
    double b = 2*dotProduct(ray.direction(), temp);
    double c = dotProduct(temp, temp) - radius()*radius();

    double discriminant = b*b - 4*a*c;

    //if discriminant <= 0 then there was no intersection
    if(discriminant > 0)
    {
        discriminant = sqrt(discriminant);
        double t = (-b - discriminant) / (2 * a);

        //check first intersection
        if (t < tmin)
        {
            //closer intersection
            t = (-b + discriminant) / (2 * a);
        }
        if (t < tmin || t > tmax)
        {
            return false;
        }

        result.t = t;
        result.normal = normalize(ray.point_at_parameter(t) - center());
        result.color = color();
        return true;
    }
    return false;
}
