cmake_minimum_required(VERSION 3.10.2)

project(bootleg-raytracer)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_DIRS
                    include
    )

set(SOURCE_FILES
                    src/main.cpp
    )

add_executable(raytracer ${SOURCE_FILES})
target_compile_options(raytracer PRIVATE -Wall -Wextra -Werror -pedantic)
target_include_directories(raytracer PRIVATE ${INCLUDE_DIRS})

