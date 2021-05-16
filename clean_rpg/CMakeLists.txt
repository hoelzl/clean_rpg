project(clean-rpg VERSION 0.0.5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add_compile_definitions(USE_CONCEPTS)

configure_file(clean_rpg_config.hpp.in clean_rpg_config.hpp)

add_library(clean-rpg-lib
        clean_rpg_app.cpp
        clean_rpg_app.hpp
        clean_rpg_event_dispatcher.cpp
        clean_rpg_event_dispatcher.hpp
        default_clean_rpg_builder.cpp
        default_clean_rpg_builder.hpp
        gridworld/layer.cpp
        gridworld/layer.hpp
        gridworld/map_data.cpp
        gridworld/map_data.hpp
        gridworld/tile_map.cpp
        gridworld/tile_map.hpp
        )
target_include_directories(clean-rpg-lib PUBLIC
        "${PROJECT_SOURCE_DIR}"
        "${PROJECT_BINARY_DIR}")
target_link_libraries(clean-rpg-lib clean-game-lib)


add_executable(clean-rpg clean_rpg.cpp)
target_link_libraries(clean-rpg clean-rpg-lib)

add_executable(clean-rpg-test test/clean_rpg_test_main.cpp test/clean_rpg_app_test.cpp test/default_clean_rpg_builder_test.cpp)
target_link_libraries(clean-rpg-test clean-rpg-lib Catch2::Catch2WithMain)
