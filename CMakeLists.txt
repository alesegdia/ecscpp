cmake_minimum_required(VERSION 2.6)
project(swonie)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/thirdparty/tmxparser/cmake" ${CMAKE_MODULE_PATH})

list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")

add_subdirectory(thirdparty/tmxparser)
add_subdirectory(src)

