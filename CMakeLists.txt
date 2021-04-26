cmake_minimum_required(VERSION 3.18)

project(csdl2)

find_package(SDL2 REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/include
  ${SDL2_INCLUDE_DIRS})

add_subdirectory(src)
