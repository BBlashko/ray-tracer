#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <iostream>
#include <cmath>

class Vector3
{
public:
    Vector3() : x_(0), y_(0), z_(0) {};
    Vector3(float x, float y, float z) : x_(x), y_(y), z_(z) {};

    // The copy constructor.
    Vector3(const Vector3& v)
    {
        x_ = v.x_;
        y_ = v.y_;
        z_ = v.z_;
    };

    // The move constructor
    Vector3(Vector3&& v)
    {
        x_ = v.x_;
        y_ = v.y_;
        z_ = v.z_;
    };

    // Destroy a vector.
    ~Vector3() {};

    // The copy assignment operator.
    Vector3& operator=(const Vector3 v)
    {
        if (this != &v)
        {
            x_ = v.x_;
            y_ = v.y_;
            z_ = v.z_;
        }
        return *this;
    };

    const float& x() const { return x_; };
    float& x() { return x_; };

    const float& y() const { return y_; };
    float& y() { return y_; };

    const float& z() const { return z_; };
    float& z() { return z_; };

    Vector3 operator+() { return *this; };
    Vector3 operator-() { return Vector3(-x_, -y_, -z_); };

	// Get the squared norm (i.e., squared length) of the vector.
    float squared_length() const
	{
		return ((x_ * x_) + (y_ * y_) + (z_ * z_));
	};

    // Get the norm (i.e., length) of the vector.
    float length() const
    {
        return std::sqrt(squared_length());
    };

    static Vector3 xNormal() { return Vector3(1, 0, 0); };
    static Vector3 yNormal() { return Vector3(0, 1, 0); };
    static Vector3 zNormal() { return Vector3(0, 0, 1); };

private:
    float x_;
    float y_;
    float z_;
};

bool operator==(const Vector3& v, const Vector3& w);
bool operator!=(const Vector3& v, const Vector3& w);

Vector3 operator*(const Vector3& v, float k);
Vector3 operator*(float k, const Vector3& v);
Vector3 operator/(const Vector3& v, const float k);

Vector3 operator+(const Vector3& v, const Vector3& w);
Vector3 operator-(const Vector3& v, const Vector3& w);

void operator+=(Vector3& v, const Vector3& w);
void operator-=(Vector3& v, const Vector3& w);
void operator*=(Vector3& v, const Vector3& w);
void operator/=(Vector3& v, const Vector3& w);

float dotProduct(const Vector3& v, const Vector3& w);
Vector3 crossProduct(const Vector3& v, const Vector3& w);
Vector3 normalize(const Vector3& v);

std::istream& operator>>(std::istream& inStream, Vector3& v);
std::ostream& operator<<(std::ostream& outStream, const Vector3& v);

#endif
