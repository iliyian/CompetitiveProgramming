#!/bin/bash
g++ $1.cpp -o $1 -g -std=c++20 -fsanitize=address,undefined
./$1 < $1.in