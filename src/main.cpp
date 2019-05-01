#include <iostream>
#include "Image/ImageWriter.h"
#include "Ray.h"
#include <glm/geometric.hpp>


glm::vec3 color(const Ray& r)
{
    vec3 unit_direction = glm::normalize(r.direction());
    float t = 0.5f*(unit_direction.y + 1.0f);
    return (1.0f-t) * glm::vec3(1.0,1.0,1.0) + t * glm::vec3(0.5,0.7,1.0);
}

int main(int argc, char** argv)
{
    const glm::uvec2 resolution(640,480);// = glm::uvec2(640,480);

    glm::vec3 pixelArray[resolution.x * resolution.y];

    glm::vec3 topLeftCorner(-2.0,1.0,-1.0);
    glm::vec3 horizontal(4.0, 0.0, 0.0);
    glm::vec3 vertical(0.0, -2.0, 0.0);
    glm::vec3 origin(0.0, 0.0, 0.0);


    std::cout << "Rendering....";
    for(uint32_t y = 0; y < resolution.y; y++)
    {
        for(uint32_t x = 0; x < resolution.x; x++)
        {
            float u = float(x) / float(resolution.x);
            float v = float(y) / float(resolution.y);
            Ray r(origin, topLeftCorner + u*horizontal + v*vertical);

            uint32_t index = y * resolution.x + x;
            pixelArray[index] = color(r);
        }
    }
    std::cout << "Done" << std::endl;


    std::cout << "Saving rendered image...";
    Image::Writer::writePPM(pixelArray, resolution, "./out.ppm");
    std::cout << "Done" << std::endl;

    return 0;
}
