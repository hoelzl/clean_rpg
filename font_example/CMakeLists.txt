project(font-example)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(font_example_config.hpp.in font_example_config.hpp)

add_executable(font-example
        font_example.cpp
        font_example_app.cpp
        font_example_app.hpp
        font_example_event_dispatcher.cpp
        font_example_event_dispatcher.hpp)
target_include_directories(font-example PUBLIC
        font_example
        "${PROJECT_BINARY_DIR}")
target_link_libraries(font-example clean-game)
target_link_libraries(font-example sfml-main)
