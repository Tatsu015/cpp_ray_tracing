project(cpp_ray_tracing)

cmake_minimum_required(VERSION 3.13)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wfatal-errors -Wundef")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_subdirectory(src)
