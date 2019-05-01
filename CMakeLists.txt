cmake_minimum_required(VERSION 3.4)

set(PROJECT_NAME "Ray Tracer")

project(${PROJECT_NAME})

set(CMAKE_MODULE_PATH 
    ${PROJECT_SOURCE_DIR}/config
    ${CMAKE_MODULE_PATH})
find_package(glm REQUIRED)

set(SOURCE 
    src/main.cpp
    )

set(HEADER
    #include/**.h
    ${GLM_INCLUDE_DIR}
    )


include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(app ${SOURCE} ${HEADER})
target_link_libraries(app)