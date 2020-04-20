cmake_minimum_required(VERSION 3.16)
project(cpp_Ex2b)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cpp_Ex2b
        doctest.h
        FamilyTree.cpp
        FamilyTree.hpp
        Test1.cpp
        Test2.cpp
        Test_ariel.cpp
        Test_hila.cpp
        TestRunner.cpp)
