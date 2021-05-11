project(clean-game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(clean-game
        app/app.hpp
        app/event_dispatcher.cpp
        app/event_dispatcher.hpp
        app/resource_manager.cpp
        app/resource_manager.hpp
        util/random_number_generator.cpp
        util/random_number_generator.hpp app/app_config.hpp)
target_link_libraries(clean-game sfml-graphics)
target_link_libraries(clean-game sfml-audio)
target_link_libraries(clean-game sfml-system)
target_link_libraries(clean-game sfml-window)
target_include_directories(clean-game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
