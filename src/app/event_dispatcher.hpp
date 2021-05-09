// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_SRC_APP_EVENT_DISPATCHER_HPP
#define CLEAN_RPG_SRC_APP_EVENT_DISPATCHER_HPP

#include "SFML/Graphics.hpp"
#include "resource_manager.hpp"

namespace cr {

class App;

class EventDispatcher {
public:
  explicit EventDispatcher(App &app);

  void dispatchEvent(const sf::Event &event);

private:
  void handleCloseEvent(const sf::Event &event);

  void handleResizedEvent(const sf::Event &event);

  void handleLostFocusEvent(const sf::Event &event);

  void handleGainedFocusEvent(const sf::Event &event);

  static void handleTextEnteredEvent(const sf::Event &event);

  static void handleKeyPressedEvent(const sf::Event &event);

  static void handleKeyReleasedEvent(const sf::Event &event);

  static void handleMouseWheelScrolledEvent(const sf::Event &event);

  static void handleMouseButtonPressedEvent(const sf::Event &event);

  static void handleMouseButtonReleasedEvent(const sf::Event &event);

  static void handleMouseMovedEvent(const sf::Event &event);

  void handleMouseEnteredEvent(const sf::Event &event);

  void handleMouseLeftEvent(const sf::Event &event);

  static void handleUnknownEvent(const sf::Event &event);

  App &            app;
  ResourceManager &resourceManager;
};

} // namespace cr
#endif // CLEAN_RPG_SRC_APP_EVENT_DISPATCHER_HPP
