cmake_minimum_required(VERSION 3.18)

project(csdl2)

find_package(SDL2 REQUIRED)
if(SDL2_FOUND)
  include_directories(${PROJECT_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIRS})
else()  # ^^^ if(SDL2_FOUND) / if(NOT SDL2_FOUND)
  include_directories(${PROJECT_SOURCE_DIR}/include)
endif()  # end if(SDL2_FOUND)

add_subdirectory(src)
