cmake_minimum_required(VERSION 3.10.2)

project(bootleg-raytracer)

set(CMAKE_CXX_STANDARD 17)

set(INSTALL_GTEST OFF)
add_subdirectory(googletest)

set(INCLUDE_DIRS
                    include
    )

set(LIB_FILES   lib/ray.cpp
                lib/vector3.cpp)

add_library(raytracerlib ${LIB_FILES})
target_compile_options(raytracerlib PRIVATE -Wall -Werror -Wextra -pedantic)
target_include_directories(raytracerlib PRIVATE ${INCLUDE_DIRS})

set(SOURCE_FILES
                    src/main.cpp
    )

set(TEST_FILES
                    tests/test_antialiasing.cpp
                    tests/unit_tests.cpp
                    tests/test_rtweekend.cpp
    )

add_executable(raytracer ${SOURCE_FILES})
target_compile_options(raytracer PRIVATE -Wall -Wextra -Werror -pedantic)
target_include_directories(raytracer PRIVATE ${INCLUDE_DIRS})
target_link_libraries(raytracer raytracerlib)

add_executable(raytracer_tests ${TEST_FILES})
target_link_libraries(raytracer_tests gtest)
target_include_directories(raytracer_tests PRIVATE ${INCLUDE_DIRS})
