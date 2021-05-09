cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(clean_rpg VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(src/clean_rpg_config.hpp.in clean_rpg_config.hpp)

set(BUILD_SHARED_LIBS False)
add_subdirectory(libs/sfml)

add_executable(clean_rpg src/clean_rpg.cpp src/app/app.cpp src/app/app.hpp src/app/event_dispatcher.cpp src/app/event_dispatcher.hpp src/app/resource_manager.cpp src/app/resource_manager.hpp)
target_include_directories(clean_rpg PUBLIC src "${PROJECT_BINARY_DIR}")
target_link_libraries(clean_rpg sfml-graphics)
target_link_libraries(clean_rpg sfml-audio)
target_link_libraries(clean_rpg sfml-system)
target_link_libraries(clean_rpg sfml-window)
target_link_libraries(clean_rpg sfml-main)

