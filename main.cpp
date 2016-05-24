// Author: Brett A. Blashko
// ID: V00759982
// Created: 05/16/2016
// Modified: 05/23/2016

#include "image.hpp"
#include "vector3.hpp"
#include "ray.hpp"
#include "camera.hpp"
#include "light.hpp"
#include "color.hpp"
#include "object.hpp"
#include "sphere.hpp"
#include "plane.hpp"

#include <iostream>
#include <vector>

//determines which ray intersection result has the smallest distance (t) value.
RayResult closest_object_in_list(std::vector<RayResult> hit_intersections)
{
    int closest_index = 0;
    for (unsigned i = 0; i < hit_intersections.size(); i++)
    {
        if (hit_intersections[i].t < hit_intersections[closest_index].t)
        {
            closest_index = i;
        }
    }
    return hit_intersections[closest_index];
}

//calculates the color at an intersect
Color calculate_color(Vector3 point_of_intersection, Vector3 ray_direction, std::vector<Object*> objects, RayResult closest_result,
                    std::vector<Light*> light_sources, float tmin, float ambient_light)
{
    //draws a checkered pattern on the an object with color checkered(1, 1, 1, 2);
    unsigned i = 0;
    if (closest_result.color.specular() == 2) {
        int square = (int) floor(point_of_intersection.x()) + (int) floor(point_of_intersection.z());

        if((square % 2) == 0)
        {
            closest_result.color.setRed(0);
            closest_result.color.setGreen(0);
            closest_result.color.setBlue(0);
        }
        else
        {
            closest_result.color.setRed(1);
            closest_result.color.setGreen(1);
            closest_result.color.setBlue(1);
        }
    }

    //Adds the ambient light factor to color to return
    Color final_color = closest_result.color * ambient_light;

    //calculates reflection on specular valued objects.
    if (closest_result.color.specular() > 0 && closest_result.color.specular() <= 1)
    {
        //determines the reflective ray
        Vector3 reflection_direction = normalize(ray_direction + 2 * closest_result.normal);
        Ray reflection_ray = Ray (point_of_intersection, reflection_direction);

        //checks if reflected ray hits an objects
        std::vector<RayResult> reflection_results;
        RayResult closest_reflection_result;
        for(i = 0; i < objects.size(); i++)
        {
            if (objects[i]->intersect(reflection_ray, tmin, 100000, closest_reflection_result))
            {
                reflection_results.push_back(closest_reflection_result);
            }
        }
        //if hit something, recursively creates another ray, then adds each reflected color to
        //the color to be returned.
        if (reflection_results.size() > 0)
        {
            closest_reflection_result = closest_object_in_list(reflection_results);
            Vector3 point_of_intersection_reflection = point_of_intersection + (reflection_direction * closest_reflection_result.t);

            Color reflection_color = calculate_color(reflection_ray.point_at_parameter(closest_reflection_result.t), reflection_direction, objects, closest_reflection_result, light_sources, tmin, ambient_light);
            final_color = final_color + (reflection_color * closest_result.color.specular());
        }
    }

    //calculate the shadows by creating a ray directly to the light source and checking
    //which objects the rays hit.
    for (i = 0; i < light_sources.size(); i++)
    {
        Vector3 light_direction = normalize(light_sources[i]->position() + (-point_of_intersection));
        float cos_angle = dotProduct(closest_result.normal, light_direction);

        if (cos_angle > 0)
        {
            bool isShadowed = false;
            Vector3 distance_to_light = normalize(-(light_sources[i]->position() + point_of_intersection));
            float distance_to_light_length = distance_to_light.length();

            Ray shadow_ray = Ray(point_of_intersection, light_sources[i]->position() + normalize(-point_of_intersection));
            std::vector<RayResult> secondary_intersect_results;

            RayResult secondary_result;
            for (unsigned j = 0; j < objects.size() && isShadowed == false; j++)
            {
                if (objects[j]->intersect(shadow_ray, tmin, 100000, secondary_result))
                {
                    secondary_intersect_results.push_back(secondary_result);
                }
            }

            //check each intersection length. if its shorter than the distance
            //then object is in a shadow.
            for (unsigned j = 0; j < secondary_intersect_results.size(); j++)
            {
                if (secondary_intersect_results[j].t <= distance_to_light_length)
                {
                    isShadowed = true;
                    break;
                }
            }

            if (!isShadowed)
            {
                final_color = final_color + (closest_result.color * light_sources[i]->color() * cos_angle);

                //reflection direction
                if (closest_result.color.specular() > 0 && closest_result.color.specular() <= 1)
                {
                    Vector3 reflection_direction = normalize(ray_direction + 2 * closest_result.normal);

                    double specular = dotProduct(reflection_direction, light_direction);
                    if (specular > 0)
                    {
                        //hardcoded specular power to 10
                        specular = pow(specular, 10);
                        final_color = final_color + (light_sources[i]->color() * (specular * closest_result.color.specular()));
                    }
                }
            }
        }
    }
    final_color.remove_excess_light();
    return final_color;
}


int main(int argc, char* argv[])
{
    //image
    int width = 800;
    int height = 400;
    int dpi = 72;
    Image image = Image(width, height, dpi);

    double aspect_ratio = (double) width / (double) height;
    float ambient_light = 0.1;
    float tmin = 0.00001f;
    float tmax = 1000;
    int anti_aliasing_depth = 4;

    //Camera
    Vector3 camera_pos(0, 2, 0);
    Vector3 look_at(0, 1.8, 2);
    Vector3 diff_btw = camera_pos - look_at;
    Vector3 camera_direction = normalize(-diff_btw);
    Vector3 camera_right = normalize(crossProduct(Vector3::yNormal(), camera_direction));
    Vector3 camera_down = crossProduct(camera_right, camera_direction);
    Camera camera = Camera(camera_pos, camera_direction, camera_right, camera_down);

    //color list
    Color white (1.0, 1.0, 1.0, 0);
    Color green (0, 1.0, 0, .2);
    Color yellow (1, 0.996, 0, 0);
    Color purple (.995, 0.071, 1, .4);
    Color maroon (0.5, 0.25, 0.25, 0);
    Color blue (0.0, 0.0, 1.0, .45);
    Color darkred (0.5, 0, 0, 0.05);
    Color red (1, 0, 0, .05);
    Color grey (0.4, 0.4, 0.4, 0.1);
    Color black (0, 0, 0, 0);
    Color checkered(1,1,1,2);
    Color background_color = black;

    //light sources
    std::vector<Light*> light_sources;
    light_sources.push_back(new Light(Vector3(-7, 10, -8), white));
    light_sources.push_back(new Light(Vector3(10, 7, 2), white));

    //objects in the scene
    std::vector<Object*> objects;
    objects.push_back(new Sphere(Vector3(-1.5, 1, 5), 1, green));
    objects.push_back(new Sphere(Vector3(2, .75, 6), .75, blue));
    objects.push_back(new Sphere(Vector3(.5, 2, 9), 2, purple));
    objects.push_back(new Plane(Vector3::yNormal(), 0, grey));

    //offsets for coords inside pixel.
    //non-anti-aliasing uses the center of the pixel.
    //anti_aliasing depends on anti_aliasing_sample size.
    float x_offset, y_offset;
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            //list of colors in anti-aliasing
            std::vector<Color> anti_aliasing_colors;
            for (int i = 0; i < anti_aliasing_depth; i++)
            {
                for (int j = 0; j < anti_aliasing_depth; j++)
                {
                    if (anti_aliasing_depth == 1)
                    {
                        //non-anti-aliasing
                        if (width > height)
                        {
                            x_offset = ((x + 0.5) / width) * aspect_ratio - (((width - height) / (double) height) / 2);
                            y_offset = ((height - y) + 0.5) / height;
                        }
                        else if (height > width)
                        {
                            x_offset = (x + 0.5) / width;
                            y_offset = (((height - y) + 0.5) / height) / aspect_ratio - (((height - width) / (double) width) / 2);
                        }
                        else {
                            x_offset = (x + 0.5) / width;
                            y_offset = ((height - y) + 0.5) / height;
                        }
                    }
                    else
                    {
                        //anti-aliasing
                        if (width > height)
                        {
                            x_offset = ((x + (double)i / ((double) anti_aliasing_depth -1)) / width) * aspect_ratio - (((width - height) / (double) height) / 2);
                            y_offset = ((height - y) + (double)i / ((double) anti_aliasing_depth -1)) / height;
                        }
                        else if (height > width)
                        {
                            x_offset = (x + (double)i / ((double) anti_aliasing_depth -1)) / width;
                            y_offset = (((height - y) + (double)i / ((double) anti_aliasing_depth -1)) / height) / aspect_ratio - (((height - width) / (double) width) / 2);
                        }
                        else {
                            x_offset = (x + (double)i / ((double) anti_aliasing_depth -1)) / width;
                            y_offset = ((height - y) + (double)i / ((double) anti_aliasing_depth -1)) / height;
                        }
                    }

                    Ray ray = Ray(camera.position(), normalize(camera.direction() + (camera.camera_right() * (x_offset - 0.5)) + (camera.camera_down() * (y_offset - 0.5))));
                    RayResult result;

                    //check each object in the scene for intersections.
                    std::vector<RayResult> hit_intersections;
                    for (unsigned i = 0; i < objects.size(); i++)
                    {
                        if (objects[i]->intersect(ray, tmin, tmax, result))
                        {
                            hit_intersections.push_back(result);
                        }
                    }

                    //determine the color found at the intersection point.
                    if (hit_intersections.size() == 0)
                    {
                        anti_aliasing_colors.push_back(background_color);
                    }
                    else
                    {
                        if (hit_intersections.size() == 1)
                        {
                            result = hit_intersections[0];
                        }
                        else if (hit_intersections.size() > 1)
                        {
                            result = closest_object_in_list(hit_intersections);
                        }

                        Vector3 point_of_intersection = ray.point_at_parameter(result.t);
                        Color color_at_intersection = calculate_color(ray.point_at_parameter(result.t), ray.direction(), objects, result, light_sources, tmin, ambient_light);
                        anti_aliasing_colors.push_back(color_at_intersection);
                    }
                }
            }
            //average the colors.
            image.set_color(x, y, average_colors(anti_aliasing_colors));
        }
    }
    image.save_image("bblashko_ray_tracer.bmp");
    return 0;
}
