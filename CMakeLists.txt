cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(clean-game-examples VERSION 0.0.1)

set(BUILD_SHARED_LIBS False)

add_subdirectory(libs/sfml)
add_subdirectory(libs/catch2)

add_subdirectory(clean_game_lib)
add_subdirectory(clean_rpg)
add_subdirectory(font_example)
add_subdirectory(moving_head)
add_subdirectory(starter_kit)

