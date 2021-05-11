project(moving-head VERSION 0.0.2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(moving_head_config.hpp.in moving_head_config.hpp)

add_executable(moving-head moving_head.cpp moving_head_app.cpp moving_head_app.hpp moving_head_event_dispatcher.cpp moving_head_event_dispatcher.hpp)
target_include_directories(moving-head PUBLIC
        moving_head
        "${PROJECT_BINARY_DIR}")
target_link_libraries(moving-head clean-game-lib)
target_link_libraries(moving-head sfml-main)
