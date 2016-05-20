#include "RGB.hpp"

RGB operator*(const float k, const RGB& a)
{
    return RGB(k * a.r(), k * a.g(), k * a.b());
}

RGB operator*(const RGB& a, const float k)
{
    return RGB(k * a.r(), k * a.g(), k * a.b());
}

RGB operator/(const RGB& a, const float k)
{
    return RGB(a.r() / k, a.g() / k, a.b() / k);
}

RGB operator+(const RGB& a, const RGB& b)
{
    return RGB(a.r() + b.r(), a.g() + b.g(), a.b() + b.b());
}

RGB operator-(const RGB& a, const RGB& b)
{
    return RGB(a.r() - b.r(), a.g() - b.g(), a.b() - b.b());
}

RGB operator*(const RGB& a, const RGB& b)
{
    return RGB(a.r() * b.r(), a.g() * b.g(), a.b() * b.b());
}

RGB operator/(const RGB& a, const RGB& b)
{
    return RGB(a.r() / b.r(), a.g() / b.g(), a.b() / b.b());
}

void operator+=(RGB& a, const RGB& b)
{
    a = RGB(a.r() + b.r(), a.g() + b.g(), a.b() + b.b());
}

void operator-=(RGB& a, const RGB& b)
{
    a = RGB(a.r() - b.r(), a.g() - b.g(), a.b() - b.b());
}

void operator*=(RGB& a, const RGB& b)
{
    a = RGB(a.r() * b.r(), a.g() * b.g(), a.b() * b.b());
}

void operator/=(RGB& a, const RGB& b)
{
    a = RGB(a.r() / b.r(), a.g() / b.g(), a.b() / b.b());
}

std::ostream& operator<<(std::ostream& outStream, const RGB& a)
{
    outStream << a.r() << " " << a.g() << " " << a.b();
    return outStream;
}
