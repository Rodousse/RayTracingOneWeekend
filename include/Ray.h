#pragma once

#include <glm/vec3.hpp>

using namespace glm;
struct Ray
{
    Ray();
    Ray(const vec3& a, const vec3& b);

    vec3 origin()const;
    vec3 direction()const;
    vec3 point_at_parameter(float t) const;

    vec3 A;
    vec3 B;

};
