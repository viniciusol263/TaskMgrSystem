#!/bin/bash

LIST_OF_RECIPES=( AccountServiceIPC )

for recipe in "${LIST_OF_RECIPES[@]}"
do
    mkdir -p "${recipe}"
    protoc --grpc_out="${recipe}" --plugin=protoc-gen-grpc="$(which grpc_cpp_plugin)" "${recipe}".proto
    protoc --cpp_out="${recipe}" "${recipe}".proto 
done