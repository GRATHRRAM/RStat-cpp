cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(RStats VERSION 1.0)

link_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCE "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(RStats ${SOURCE})

target_link_libraries(RStats PRIVATE curl raylib m winmm gdi32 user32 kernel32)

add_compile_options(-Wall -Wextra)