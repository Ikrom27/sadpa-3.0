cmake_minimum_required(VERSION 3.23)
project(HashTable)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HashTable
        Book.cpp
        Book.h
        Headler.cpp
        Headler.h
        HeshMap.cpp
        HeshMap.h
        main.cpp
        Structure.cpp)
