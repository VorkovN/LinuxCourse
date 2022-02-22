cmake_minimum_required(VERSION 3.21)
project(unit5_7 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC")


add_executable(unit5_7 solution3.c)
