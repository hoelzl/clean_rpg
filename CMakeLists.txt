cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(clean_rpg VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(src/clean_rpg_config.h.in clean_rpg_config.h)

add_subdirectory(libs/sfml)

add_executable(clean_rpg src/clean_rpg.cpp)
target_include_directories(clean_rpg PUBLIC "${PROJECT_BINARY_DIR}")
target_link_libraries(clean_rpg sfml-graphics)
target_link_libraries(clean_rpg sfml-audio)

