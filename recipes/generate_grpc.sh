#!/bin/bash

LIST_OF_RECIPES=( AccountServiceIPC )

for recipe in "${LIST_OF_RECIPES[@]}"
do
    mkdir -p "${recipe}"
    protoc --proto_path="${PWD}" --grpc_out="${recipe}" --plugin=protoc-gen-grpc="$(which grpc_cpp_plugin)" "${recipe}".proto AccountStructs.proto
    protoc --cpp_out="${recipe}" "${recipe}".proto AccountStructs.proto
done