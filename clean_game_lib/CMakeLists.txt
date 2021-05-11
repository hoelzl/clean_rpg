project(clean-game-lib VERSION 0.0.3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(clean_game_lib_config.hpp.in clean_game_lib_config.hpp)

add_library(clean-game-lib
        clean_game_lib_config.hpp
        app/app.hpp
        app/app_config.hpp
        app/event_dispatcher.cpp
        app/event_dispatcher.hpp
        app/resource_manager.cpp
        app/resource_manager.hpp
        util/random_number_generator.cpp
        util/random_number_generator.hpp)
target_link_libraries(clean-game-lib sfml-graphics)
target_link_libraries(clean-game-lib sfml-audio)
target_link_libraries(clean-game-lib sfml-system)
target_link_libraries(clean-game-lib sfml-window)
target_include_directories(clean-game-lib PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}"
        "${PROJECT_BINARY_DIR}")
