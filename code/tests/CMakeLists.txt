##################
# Add GoogleTest #
##################

set(INSTALL_GTEST OFF)
add_subdirectory(googletest)

###################
# Unit test files #
###################

set(TEST_FILES
    unittests/unit_tests.cpp
    unittests/test_utils.cpp
)

###############################
# Statically linked libraries #
###############################

set(TEST_LINK_LIBRARIES
    gtest
)

add_executable(raytracer_tests ${TEST_FILES})

target_include_directories(raytracer_tests PRIVATE ${INCLUDE_DIRS})
target_link_libraries(raytracer_tests ${TEST_LINK_LIBRARIES})

set_target_properties(raytracer_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
