#!/bin/bash

CURRENT_DIR=$(pwd)
BUILD_DIR="${CURRENT_DIR}/build"
C_COMPILER=$(which gcc)
CXX_COMPILER=$(which g++)

CONAN_OUTPUT=$(conan install . -of="${CURRENT_DIR}/libs/ConanLibs" --build=missing 2>&1)

if [ $? -eq 0 ]; then
    echo "Conan has successfully installed the remote dependencies"
else 
    echo "Conan couldn't install remote dependencies: ${CONAN_OUTPUT}"
fi

CMAKE_CONFIG=$(cmake --no-warn-unused-cli -DCMAKE_BUILD_TYPE:STRING=Release -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_C_COMPILER:FILEPATH="${C_COMPILER}" -DCMAKE_CXX_COMPILER:FILEPATH="${CXX_COMPILER}" -S"${CURRENT_DIR}" -B"${BUILD_DIR}" -G "Unix Makefiles" 2>&1)

if [ $? -eq 0 ]; then
    echo "CMake has successfully configured the environment"
else 
    echo "CMake couldn't configure the environment: ${CMAKE_CONFIG}"
fi

CMAKE_BUILD=$(cmake --build "${BUILD_DIR}" --config Release --target all -j 18 -- 2>&1)

if [ $? -eq 0 ]; then
    echo "CMake has successfully built"
else 
    echo "CMake couldn't build: ${CMAKE_BUILD}"
fi