// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "app.hpp"
#include <iostream>

namespace cr {

App::App(unsigned int width, unsigned int height, const std::string &title)
    : mainWindow{sf::VideoMode{width, height}, title} {
  setWindowParameters();
}

void App::loadResources() {
  resourceManager.loadResources();
  std::cout << "Loading resources" << std::endl;
}

int App::runEventLoop() {
  while (mainWindow.isOpen()) {
    processPendingEvents();
    renderNextFrame();
  }
  return 0;
}

void App::close() { mainWindow.close(); }

void App::setWindowParameters() {
  backgroundColor = resourceManager.randomColor();
  mainWindow.setVerticalSyncEnabled(true);
}

void App::processPendingEvents() {
  sf::Event event{};
  while (mainWindow.pollEvent(event)) {
    dispatchEvent(event);
  }
}

void App::dispatchEvent(const sf::Event &event) {
  eventDispatcher.dispatchEvent(event);
}

void App::renderNextFrame() {
  mainWindow.clear(backgroundColor);
  mainWindow.display();
}

} // namespace cr
