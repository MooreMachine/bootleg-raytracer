#!/bin/bash

VERSION=$(cat toolchain/README.md | grep "Version" | awk '{print $2}')

docker run \
    --rm \
    -it \
    -v $(pwd)/code:/home \
    -w '/home' \
    mooremachine/easyubuntu:$VERSION
