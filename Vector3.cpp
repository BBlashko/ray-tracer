#include "Vector3.hpp"

bool operator==(const Vector3& v, const Vector3& w)
{
    if (v.x() != w.x()) return false;
    if (v.y() != w.y()) return false;
    if (v.z() != w.z()) return false;
    return true;
}

bool operator!=(const Vector3& v, const Vector3& w)
{
    return !(v == w);
}

Vector3 operator*(const Vector3& v, float k)
{
    return Vector3(v.x() * k, v.y() * k, v.z() * k);
}

Vector3 operator*(float k, const Vector3& v)
{
    return Vector3(v.x() * k, v.y() * k, v.z() * k);
}

Vector3 operator/(const Vector3& v, const float k)
{
    return Vector3(v.x() / k, v.y() / k, v.z() / k);
}

Vector3 operator+(const Vector3& v, const Vector3& w)
{
    return Vector3(v.x() + w.x(), v.y() + w.y(), v.z() + w.z());
}

Vector3 operator-(const Vector3& v, const Vector3& w)
{
    return Vector3(v.x() - w.x(), v.y() - w.y(), v.z() - w.z());
}

void operator+=(Vector3& v, const Vector3& w)
{
    v = Vector3(v.x() + w.x(), v.y() + w.y(), v.z() + w.z());
}

void operator-=(Vector3& v, const Vector3& w)
{
    v = Vector3(v.x() - w.x(), v.y() - w.y(), v.z() - w.z());
}

void operator*=(Vector3& v, const Vector3& w)
{
    v = Vector3(v.x() * w.x(), v.y() * w.y(), v.z() * w.z());
}

void operator/=(Vector3& v, const Vector3& w)
{
    v = Vector3(v.x() / w.x(), v.y() / w.y(), v.z() / w.z());
}

float dotProduct(const Vector3& v, const Vector3& w)
{
    return ((v.x() * w.x()) + (v.y() * w.y()) + (v.z() * w.z()));
}

Vector3 crossProduct(const Vector3& v, const Vector3& w)
{
    float x = ((v.y() * w.z()) - (v.z() * w.y()));
    float y = ((v.z() * w.x()) - (v.x() * w.z()));
    float z = ((v.x() * w.y()) - (v.y() * w.x()));
    return Vector3(x, y, z);
}

std::istream& operator>>(std::istream& inStream, Vector3& v)
{
    float x = 0;
    float y = 0;
    float z = 0;
    inStream >> x >> y >> z;
    Vector3(x, y, z);
    return inStream;
}

std::ostream& operator<<(std::ostream& outStream, const Vector3& v)
{
    outStream << v.x() << " " << v.y() << " " << v.z();
    return outStream;
}
