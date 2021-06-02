cmake_minimum_required(VERSION 3.19)
project(SortedMap_BST)

set(CMAKE_CXX_STANDARD 14)

add_executable(SortedMap_BST SortedMap.cpp SortedMap.h SMIterator.cpp SMIterator.h ShortTest.cpp ShortTest.h ExtendedTest.cpp ExtendedTest.h App.cpp)