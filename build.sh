#!/bin/bash

mkdir -p build
cd build
cmake ../
START=$(date +%s)
make
END=$(date +%s)
echo "Total Build time (real) = $(( $END - $START )) seconds"
