cmake_minimum_required(VERSION 3.5)

project(Arkad LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set( project_sources main.cpp game.cpp)

add_executable(Arkad main.cpp)
