cmake_minimum_required(VERSION 3.10.2)

project(bootleg-raytracer)

set(CMAKE_CXX_STANDARD 17)

#######################
# Include directories #
#######################

set(INCLUDE_DIRS
    ${PROJECT_SOURCE_DIR}/include
)

#################
# Library files #
#################

set(LIB_FILES
    lib/camera.cpp
    lib/half_b_quadratic_formula.cpp
    lib/hittablelist.cpp
    lib/ray.cpp
    lib/sphere.cpp
    lib/vector3.cpp
)

###############
# Add library #
###############

add_library(raytracerlib ${LIB_FILES})
target_include_directories(raytracerlib PRIVATE ${INCLUDE_DIRS})
target_compile_options(raytracerlib PRIVATE -Wall -Werror -Wextra -pedantic)
set_target_properties(raytracerlib PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

###################
# Add application #
###################

set(SOURCE_FILES
    src/main.cpp
)

add_executable(raytracer ${SOURCE_FILES})
target_include_directories(raytracer PRIVATE ${INCLUDE_DIRS})
target_link_libraries(raytracer raytracerlib)
target_compile_options(raytracer PRIVATE -Wall -Wextra -Werror -pedantic)
set_target_properties(raytracer PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

############################
# Add other CMakeLists.txt #
############################

add_subdirectory(tests)
