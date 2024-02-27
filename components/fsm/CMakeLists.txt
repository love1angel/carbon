cmake_minimum_required(VERSION 3.26)
project(fsm)

set(CMAKE_CXX_STANDARD 23)

find_package(Boost REQUIRED)

file(GLOB HDRS "${CMAKE_CURRENT_SOURCE_DIR}/include/fsm/*.hpp")
file(GLOB SRCS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(${PROJECT_NAME} SHARED ${HDRS} ${SRCS})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
    PRIVATE
        ${Boost_INCLUDE_DIRS}
)
