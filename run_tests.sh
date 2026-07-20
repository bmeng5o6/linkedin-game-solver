#!/bin/bash
g++ -std=c++17 -I. backend/gameSolvers/tango/tests/test_board.cpp -o run_tests && ./run_tests