project(clean-rpg)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add_compile_definitions(USE_CONCEPTS)

configure_file(clean_rpg_config.hpp.in clean_rpg_config.hpp)

add_executable(clean-rpg
        clean_rpg.cpp
        clean_rpg_app.cpp
        clean_rpg_app.hpp
        clean_rpg_event_dispatcher.cpp
        clean_rpg_event_dispatcher.hpp
        gridworld/layer.cpp
        gridworld/layer.hpp
        gridworld/map_data.cpp
        gridworld/map_data.hpp
        gridworld/tile_map.cpp
        gridworld/tile_map.hpp)
target_include_directories(clean-rpg PUBLIC
        clean_rpg
        "${PROJECT_BINARY_DIR}")
target_link_libraries(clean-rpg clean-game-lib)
