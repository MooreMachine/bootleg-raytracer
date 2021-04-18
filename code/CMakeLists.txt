cmake_minimum_required(VERSION 3.10.2)

project(bootleg-raytracer)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_DIRS
                    ${PROJECT_SOURCE_DIR}/include
    )

set(LIB_FILES   lib/hittablelist.cpp
                lib/ray.cpp
                lib/sphere.cpp
                lib/vector3.cpp)

add_library(raytracerlib ${LIB_FILES})
target_compile_options(raytracerlib PRIVATE -Wall -Werror -Wextra -pedantic)
target_include_directories(raytracerlib PRIVATE ${INCLUDE_DIRS})

set(SOURCE_FILES
                    src/main.cpp
    )

add_executable(raytracer ${SOURCE_FILES})
target_compile_options(raytracer PRIVATE -Wall -Wextra -Werror -pedantic)
target_include_directories(raytracer PRIVATE ${INCLUDE_DIRS})
target_link_libraries(raytracer raytracerlib)

add_subdirectory(tests)
