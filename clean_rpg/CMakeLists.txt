project(clean-rpg)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(clean_rpg_config.hpp.in clean_rpg_config.hpp)

add_executable(clean-rpg clean_rpg.cpp clean_rpg_app.cpp clean_rpg_app.hpp clean_rpg_event_dispatcher.cpp clean_rpg_event_dispatcher.hpp clean_rpg_app_config.cpp clean_rpg_app_config.hpp)
target_include_directories(clean-rpg PUBLIC
        clean_rpg
        "${PROJECT_BINARY_DIR}")
target_link_libraries(clean-rpg clean-game)
target_link_libraries(clean-rpg sfml-main)
