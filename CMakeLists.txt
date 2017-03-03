cmake_minimum_required(VERSION 3.6)
project(Rabbits)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp rabbit_t.cpp rabbit_t.h LinkedList/dll_node_t.cpp LinkedList/dll_node_t.h LinkedList/dll_t.cpp LinkedList/dll_t.h Colony/colony_t.cpp Colony/colony_t.h Colony/utilities.cpp Colony/utilities.h)
add_executable(Rabbits ${SOURCE_FILES})