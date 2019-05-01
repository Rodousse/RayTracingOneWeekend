cmake_minimum_required(VERSION 3.4)

set(PROJECT_NAME "RayTracer")

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH 
    ${PROJECT_SOURCE_DIR}/config
    ${CMAKE_MODULE_PATH})
find_package(glm REQUIRED)

set(SOURCE 
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/Ray.cpp
    ${PROJECT_SOURCE_DIR}/src/Image/PPMWriter.cpp
    )

set(HEADER
    ${PROJECT_SOURCE_DIR}/include/Ray.h
    ${PROJECT_SOURCE_DIR}/include/Image/ImageWriter.h
    ${GLM_INCLUDE_DIR}
    )


include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(${PROJECT_NAME} ${SOURCE} ${HEADER})
