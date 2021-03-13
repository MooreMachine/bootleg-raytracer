FROM ubuntu:18.04

RUN apt-get update \
    && apt-get -y install \
    build-essential

RUN apt-get -y install cmake

