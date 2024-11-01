#!/bin/bash

g++ ./sample/main.cpp       \
    ./logger/src/*.cpp      \
    -I./logger/api          \
    -I./logger/include      \
    -std=c++11              \
    -DLOG_DISABLE           \
    -o main
