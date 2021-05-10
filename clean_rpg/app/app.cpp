// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "app.hpp"
#include <iostream>

namespace cr {

App::App(unsigned int width, unsigned int height, const std::string& title)
    : mainWindow{sf::VideoMode{width, height}, title} {
  setWindowParameters();
}

void App::loadResources() {
  resourceManager.addSprite("head", "head.png", 300.f, 100.f);
  sprite = &resourceManager.getSprite("head");
}

float convertCoordinate(float coord, float max = 600.f) {
  return std::clamp(coord, 50.f, max);
}

void App::moveHead(float newX, float newY) {
  auto& sprite{getResourceManager().getSprite("head")};
  sprite.setPosition(convertCoordinate(newX, 450.f),
                     convertCoordinate(newY, 150.f));
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
  backgroundColor = rng.randomColor();
  mainWindow.setVerticalSyncEnabled(true);
}

void App::processPendingEvents() {
  sf::Event event{};
  while (mainWindow.pollEvent(event)) {
    dispatchEvent(event);
  }
}

void App::dispatchEvent(const sf::Event& event) {
  eventDispatcher.dispatchEvent(event);
}

void App::renderNextFrame() {
  mainWindow.clear(backgroundColor);
  if (sprite) {
    mainWindow.draw(*sprite);
  }
  mainWindow.display();
}

} // namespace cr
