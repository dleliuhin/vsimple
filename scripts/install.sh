#!/bin/bash

sudo apt-get install sudo apt-get install build-essential gcc-5 g++5 cmake make lcov gcovr
sudo apt install libgtest-dev
cd /usr/src/gtest/
sudo cmake -DBUILD_SHARED_LIBS=ON
sudo make
sudo cp *.so /usr/lib
