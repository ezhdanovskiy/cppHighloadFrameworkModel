#!/bin/bash

cmake -DCMAKE_LEGACY_CYGWIN_WIN32=0 ../cppSwipe/
make -j3

lcov --zerocounters --directory .
#ctest
./swipe

lcov --capture --directory ./ --base-directory ./ --output-file coverage.info
lcov -r coverage.info "/usr*" "*gmock*" -o coverage.info

genhtml coverage.info --output-directory coverage.out
