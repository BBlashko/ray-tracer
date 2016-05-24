#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "vector3.hpp"

class Camera
{
public:
    Camera ();
    Camera (Vector3 position, Vector3 direction, Vector3 right, Vector3 down);

    Vector3 position () { return _camera_position; };
    Vector3 direction () { return _camera_direction; };
    Vector3 camera_right () { return _camera_right; };
    Vector3 camera_down () { return _camera_down; };

private:
    Vector3 _camera_position;
    Vector3 _camera_direction;
    Vector3 _camera_right;
    Vector3 _camera_down;
};

Camera::Camera ()
{
    _camera_position = Vector3(0, 0, 0);
    _camera_direction = Vector3(0, 0, 1);
    _camera_right = Vector3(0, 0, 0);
    _camera_down = Vector3(0, 0, 0);
}

Camera::Camera (Vector3 position, Vector3 direction, Vector3 right, Vector3 down)
{
    _camera_position = position;
    _camera_direction = direction;
    _camera_right = right;
    _camera_down = down;
}
#endif
