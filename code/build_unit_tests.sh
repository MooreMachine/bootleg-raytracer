#!/bin/bash

mkdir -p build
cd build
cmake ..
make raytracer_tests
