cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(clean-game-examples)

set(BUILD_SHARED_LIBS False)

add_subdirectory(libs/sfml)
add_subdirectory(clean_game_lib)
add_subdirectory(clean_rpg)
add_subdirectory(font_example)
add_subdirectory(moving_head)
add_subdirectory(starter_kit)
