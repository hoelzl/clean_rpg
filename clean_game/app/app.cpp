// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "app.hpp"
#include <cassert>
#include <iostream>

namespace cg {

void App::init() {
  setWindowParameters();
  loadResources();
  isInitialized = true;
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
  assert(isInitialized);
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

void App::loadResources() {}

void App::renderNextFrame() {
  getMainWindow().clear(getBackgroundColor());
  getMainWindow().display();
}

void App::processPendingEvents() {
  sf::Event event{};
  while (mainWindow.pollEvent(event)) {
    dispatchEvent(event);
  }
}

void App::dispatchEvent(const sf::Event& event) {
  if (eventDispatcher) {
    eventDispatcher->dispatchEvent(event);
  }
}

} // namespace cg
