cmake_minimum_required(VERSION 3.23)
project(Doubly_Linked_List)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Doubly_Linked_List
        List.h
        List.hpp
        main.cpp
        )
