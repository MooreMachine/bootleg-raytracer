#!/bin/bash

VERSION=$(cat toolchain/README.md | grep "Version" | awk '{ print $2 }')

if [ -z $VERSION ]
then
    echo "Please make sure your toolchain's README.md file has a Version number."
    exit 1
fi

echo "Running new container..."

CONTAINER_ID=$(docker run \
    --name build_test \
    --rm \
    -it \
    -d \
    -v $(pwd)/code:/home \
    mooremachine/easyubuntu:$VERSION)

echo "Building app..."

docker exec \
    -w '/home' \
    build_test \
    sh -c './build_app.sh; echo "::set-output name=build_result::$?"'

echo "Running app..."

docker exec \
    -w '/home' \
    build_test \
    sh -c './build/bin/raytracer > /dev/null ; echo "::set-output name=quick_run_result::$?"'

echo "Building unit tests..."

docker exec \
    -w '/home' \
    build_test \
    sh -c './build_unit_tests.sh; echo "::set-output name=build_unit_tests_result::$?"'

echo "Running unit tests..."

docker exec \
    -w '/home' \
    build_test \
    sh -c './build/bin/raytracer_tests --gtest_color=yes; echo "::set-output name=run_unit_tests_result::$?"'

echo "Stopping container..."

docker container stop -t 0 $CONTAINER_ID
