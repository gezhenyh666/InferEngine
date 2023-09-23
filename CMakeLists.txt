
cmake_minimum_required(VERSION 3.10.1)

project(InferEngine)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SRC_LIST "./src/*.cpp")

add_executable(InferEngine src/main.cpp
        ${SRC_LIST})
