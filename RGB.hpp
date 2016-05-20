#ifndef RGB_hpp
#define RGB_hpp

#include <iostream>

class RGB
{
public:
    RGB() : r_(0), g_(0), b_(0) {};
    RGB(float r, float g, float b) : r_(r), g_(g), b_(b) {};

    //copg constructor
    RGB(const RGB& a)
    {
        r_ = a.r_;
        g_ = a.g_;
        b_ = a.b_;
    };

    //move constructor
    RGB(RGB&& a)
    {
        r_ = a.r_;
        g_ = a.r_;
        b_ = a.b_;
    };

    //deconstructor? needed?
    ~RGB() {};

    // The copy assignment operator.
    RGB& operator=(const RGB& a)
    {
        if (this != &a)
        {
            r_ = a.r_;
            g_ = a.g_;
            b_ = a.b_;
        }
        return *this;
    };

    // The move assignment operator.
    RGB& operator=(RGB&& a)
    {
        r_ = a.r_;
        g_ = a.g_;
        b_ = a.g_;
        return *this;
    };

    const float& r() const { return r_; };
    float& r() { return r_; };

    const float& g() const { return g_; };
    float& g() { return g_; };

    const float& b() const { return b_; };
    float& b() { return b_; };

    void setRed(float r) { r_ = r; };
    void setGreen(float g) { g_ = g; };
    void setBlue(float b) { b_ = b; };

    RGB operator+() { return *this; };
    RGB operator-() { return RGB(-r_, -g_, -b_); };

    void clamp()
    {
        if (r_ > 1.0) { r_ = 1.0; };
        if (g_ > 1.0) { g_ = 1.0; };
        if (b_ > 1.0) { b_ = 1.0; };
    }

private:
    float r_;
    float g_;
    float b_;
};

RGB operator*(const float k,  const RGB& a);
RGB operator*(const RGB& a,  const float k);
RGB operator/(const RGB& a, const float k);

RGB operator+(const RGB& a, const RGB& b);
RGB operator-(const RGB& a, const RGB& b);
RGB operator*(const RGB& a, const RGB& b);
RGB operator/(const RGB& a, const RGB& b);

void operator+=(RGB& a, const RGB& b);
void operator-=(RGB& a, const RGB& b);
void operator*=(RGB& a, const RGB& b);
void operator/=(RGB& a, const RGB& b);

std::ostream& operator<<(std::ostream& outStream, const RGB& v);


#endif
