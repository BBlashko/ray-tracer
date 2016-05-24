Environment:
    - Built and tested on linux
    - gcc (GCC) 6.1.1
    - calls system("imlib2_view bblashko_ray_tracer.bmp"); to automatically open saved image.
        \-> will fail to open if imlib2_view does not exist, but will always save successfully.

Currently implemented features:

    - floor plane
    - 3 spheres
    - reflection depending on specular value
    - shading on the spheres
    - hard shadow from the sphere on the floor
    - camera with fixed location and direction
    - illumination by multiple light sources
    - reflective surfaces
    - supersampling anti-aliasing
