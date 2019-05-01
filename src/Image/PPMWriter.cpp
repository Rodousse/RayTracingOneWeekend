#include "Image/ImageWriter.h"
#include <fstream>
#include <exception>

namespace Image
{
namespace Writer
{

int writePPM(const glm::vec3 *imageArray, glm::uvec2 resolution, char* path)
{
    std::ofstream file;
    file.open(path, std::ofstream::out);
    if(file.is_open() == false)
    {
        throw std::runtime_error("Can't save the file, check the path or your permissions");
    }

    file << "P3\n" << resolution.x << " " << resolution.y << "\n255\n";
    for(uint32_t y = 0; y < resolution.y; y++)
    {
        for(uint32_t x = 0; x < resolution.x; x++)
        {
            uint32_t index = y * resolution.x + x;
            glm::ivec3 pix(
                        int(255.99f * (imageArray[index]).x),
                        int(255.99f * (imageArray[index]).y),
                        int(255.99f * (imageArray[index]).z));
            file << pix.x << " " << pix.y << " " << pix.z << '\n';
        }
    }

    file.close();
    return 0;
}

}
}
