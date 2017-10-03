cmake_minimum_required(VERSION 3.5)
project(PrimAndDjikstra)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp minheap.tcc graph.cpp graph.h)
add_executable(PrimAndDjikstra ${SOURCE_FILES})