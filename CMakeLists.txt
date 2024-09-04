cmake_minimum_required(VERSION 3.24)
project(avl_tree)

set(CMAKE_CXX_STANDARD 14)

include_directories(test-unit)

add_executable(avl_tree
        test-unit/catch.hpp
        test-unit/test.cpp src/AVLTree.h src/Node.h src/helpers.h)
