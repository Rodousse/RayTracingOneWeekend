#pragma once
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

namespace Image
{
namespace Writer
{

int writePPM(const glm::vec3 *imageArray, glm::uvec2 resolution, char* path);


}
}
