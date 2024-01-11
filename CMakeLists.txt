cmake_minimum_required(VERSION 3.15)
project(project1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -pedantic -pedantic-errors")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-limit-debug-info")

set(SOURCE_FILES
        DNA_Strand.cpp
        DNA_Strand.h
        DNAtest.cpp)

add_executable(project1 ${SOURCE_FILES})