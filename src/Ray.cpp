#include "Ray.h"

Ray::Ray(){}

Ray::Ray(const vec3& a, const vec3& b):
    A(a),
    B(b)
{

}

vec3 Ray::origin()const
{
    return A;
}

vec3 Ray::direction()const
{
    return B;
}

vec3 Ray::point_at_parameter(float t) const
{
    return A + t*B;
}
