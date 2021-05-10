// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_SRC_APP_APP_HPP
#define CLEAN_RPG_SRC_APP_APP_HPP

#include "SFML/Graphics.hpp"
#include "event_dispatcher.hpp"
#include "resource_manager.hpp"
#include <random>
#include <string>

namespace cr {
class App {
public:
  explicit App(unsigned int width = 800, unsigned int height = 600,
               const std::string &title = "Clean RPG");

  void loadResources();

  sf::RenderWindow &getMainWindow() { return mainWindow; }

  ResourceManager &getResourceManager() { return resourceManager; }

  sf::Color getBackgroundColor() const { return backgroundColor; }

  void setBackgroundColor(sf::Color color) { backgroundColor = color; }

  int runEventLoop();

  void close();

private:
  void setWindowParameters();

  void processPendingEvents();

  void dispatchEvent(const sf::Event &event);

  void renderNextFrame();

  EventDispatcher  eventDispatcher{*this};
  ResourceManager  resourceManager{};
  sf::RenderWindow mainWindow;
  sf::Color        backgroundColor = sf::Color::Black;
  sf::Sprite *     sprite{};
};
} // namespace cr

#endif // CLEAN_RPG_SRC_APP_APP_HPP
