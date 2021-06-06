#!/bin/bash

cd cmake/

if [ -d "build" ]; 
then
	rm -rf build/*
else
        mkdir -p build
fi

cd build

cmake ..

make -j $(($(nproc) - 1))
