cmake_minimum_required(VERSION 4.0)
project(TP_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(TP_cpp main.cpp)


target_link_libraries(TP_cpp
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)

