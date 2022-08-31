cmake_minimum_required(VERSION 3.23)
project(Linked_List)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Linked_List
        List.h
        List.hpp
        main.cpp
        test_list.cpp)
