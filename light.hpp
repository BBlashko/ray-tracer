#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "vector3.hpp"
#include "color.hpp"

class Light
{
public:
    Light () : _position(Vector3(0, 0, 0)), _color(Color(1, 1, 1, 0)) {};
    Light (Vector3 position, Color color) : _position(position), _color(color) {};
    ~Light() {};

    Vector3 position(){ return _position; };
    Color color(){ return _color; };

private:
    Vector3 _position;
    Color _color;
};
#endif
