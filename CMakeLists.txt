cmake_minimum_required(VERSION 3.28.3)
project(TP_cpp)

set(CMAKE_CXX_STANDARD 20)
include_directories(${CMAKE_SOURCE_DIR}/utils/inc)


file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/utils/src/*.cpp)
add_executable(TP_cpp main.cpp ${SRC_FILES})



target_link_libraries(TP_cpp
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)



enable_testing()

file(GLOB TEST_FILES ${CMAKE_SOURCE_DIR}/tests/*.cpp)
foreach(TEST_SRC ${TEST_FILES})
    get_filename_component(TEST_NAME ${TEST_SRC} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SRC} ${SRC_FILES})
    target_link_libraries(${TEST_NAME}
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
    )
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()

