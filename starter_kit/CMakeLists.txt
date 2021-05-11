project(starter-kit)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(starter_kit_config.hpp.in starter_kit_config.hpp)

add_executable(starter-kit
        starter_kit.cpp
        starter_kit_app.cpp
        starter_kit_app.hpp
        starter_kit_event_dispatcher.cpp
        starter_kit_event_dispatcher.hpp)
target_include_directories(starter-kit PUBLIC
        starter_kit
        "${PROJECT_BINARY_DIR}")
target_link_libraries(starter-kit clean-game)
target_link_libraries(starter-kit sfml-main)
