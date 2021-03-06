#!/bin/bash

docker run --rm -it -v $(pwd)/code:/home -w '/home' mooremachine/easyubuntu:0.1.0
