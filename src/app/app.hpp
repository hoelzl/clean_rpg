// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_SRC_APP_APP_HPP
#define CLEAN_RPG_SRC_APP_APP_HPP

#include "SFML/Graphics.hpp"
#include <random>
#include <string>

namespace cr {
class App {
public:
  void setWindowParameters();
  explicit App(unsigned int width = 800, unsigned int height = 600,
               const std::string &title = "Clean RPG")
      : main_window{sf::VideoMode{width, height}, title} {
    setWindowParameters();
  }

  sf::RenderWindow &getMainWindow() { return main_window; }
  int runEventLoop();

private:
  sf::Uint8 randomColorValue();
  sf::Color randomColor();

  void processPendingEvents();
  void dispatchEvent(const sf::Event &event);

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

  void renderNextFrame();

  std::random_device rd{};
  std::default_random_engine random_engine{rd()};
  std::uniform_int_distribution<unsigned short> random_color_distribution{0,
                                                                          255};

  sf::RenderWindow main_window;
  sf::Color background_color = sf::Color::Black;
};
} // namespace cr

#endif // CLEAN_RPG_SRC_APP_APP_HPP
