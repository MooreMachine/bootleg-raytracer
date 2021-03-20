#!/bin/bash

VERSION=$(cat README.md | grep "Version" | awk '{print $2}')

docker run \
    --rm \
    -it \
    -v $(pwd)/code:/home \
    -w '/home' \
    mooremachine/easyubuntu:$VERSION
