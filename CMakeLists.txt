cmake_minimum_required(VERSION 3.31.5)

project(phase)
include_directories(include)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

add_executable(phase src/main.cpp src/readFile.cpp src/phaseEditor.cpp)
target_link_libraries(phase ${CURSES_LIBRARIES})
