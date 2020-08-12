
cmake_minimum_required(VERSION 3.17)

project(app)

enable_testing()

set(CMAKE_CXX_STANDARD 20)

include(cmake/CMakeLists.gtest.cmake)
#include(cmake/CMakeLists.qt.cmake)

add_subdirectory(util)
add_subdirectory(stocklib)
add_subdirectory(stocks)
add_subdirectory(redux)
add_subdirectory(gui)
