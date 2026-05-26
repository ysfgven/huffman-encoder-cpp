cmake_minimum_required(VERSION 3.30)
project(Huffman)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(Huffman
        src/main.cpp
        src/PriorityQueue.cpp
        src/Node.cpp)