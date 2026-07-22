#!/bin/bash
g++ -std=c++17 -Wall -Wextra -g -I. \
    backend/gameSolvers/tango/src/*.cpp \
    backend/gameSolvers/tango/tests/*.cpp \
    -o run_tests && ./run_tests