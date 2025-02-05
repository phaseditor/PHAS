cmake_minimum_required(VERSION 3.31.5)

project(phase)
include_directories(include)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(phase src/main.cpp src/readFile.cpp)
