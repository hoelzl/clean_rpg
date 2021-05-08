// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "SFML/Window.hpp"
#include "clean_rpg_config.hpp"
#include <iostream>

int main() {
  std::cout << "Clean RPG Version " << CLEAN_RPG_VERSION_MAJOR << "."
            << CLEAN_RPG_VERSION_MINOR << "." << CLEAN_RPG_VERSION_PATCH << " "
            << "is up and running!" << std::endl;

  sf::Window window{sf::VideoMode{800, 600}, "Clean RPG"};
  while (window.isOpen()) {
    sf::Event event{};
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
  }
  return 0;
}
