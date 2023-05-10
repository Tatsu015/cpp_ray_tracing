project(cpp_ray_tracing)

cmake_minimum_required(VERSION 3.13)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall")

file(GLOB SRC_FILES *.cpp)

add_executable(cpp_ray_tracing ${SRC_FILES})
