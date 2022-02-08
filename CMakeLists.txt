cmake_minimum_required(VERSION 3.5)

project(intellias_task1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(intellias_task1
    main.cpp
    Matrix.h
    Matrix.cpp
    Timer.h
    Timer.cpp)
