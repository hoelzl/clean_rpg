// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_SRC_APP_APP_HPP
#define CLEAN_RPG_SRC_APP_APP_HPP

#include "SFML/Window.hpp"
#include <string>

namespace cr {
class App {
private:
  sf::Window main_window;

public:
  explicit App(unsigned int width = 800, unsigned int height = 600,
               const std::string &title = "Clean RPG")
      : main_window{sf::VideoMode{width, height}, title} {}

  int runEventLoop() {
    while (main_window.isOpen()) {
      handleNextEvent();
    }
    return 0;
  }

  void handleNextEvent() {
    sf::Event event{};
    while (main_window.pollEvent(event)) {
      dispatchEvent(event);
    }
  }

  void dispatchEvent(const sf::Event &event) {
    if (event.type == sf::Event::Closed) {
      main_window.close();
    }
  }
};
} // namespace cr

#endif // CLEAN_RPG_SRC_APP_APP_HPP
