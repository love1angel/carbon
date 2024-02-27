cmake_minimum_required(VERSION 3.26)
project(carbon)

set(CMAKE_CXX_STANDARD 23)

find_package(Boost REQUIRED)

add_subdirectory(fsm)
