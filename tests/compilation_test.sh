#!/usr/bin/bash

# compiling cpp files
echo "Compiling src/* files and checking for error..."
for file in `find src/ -name *.cpp`
do
    echo "Compiling $file and checking for errors"
    g++ $file
done
