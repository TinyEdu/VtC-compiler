#!/bin/bash

clear

cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .

./MyProject ../typemap.csv