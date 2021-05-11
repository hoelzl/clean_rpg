// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "clean_rpg_event_dispatcher.hpp"
#include <iostream>

namespace cr {

void CleanRpgEventDispatcher::handleCloseEvent(const sf::Event& event) {
  std::cout << "Closing application." << std::endl;
  EventDispatcher::handleCloseEvent(event);
}

void CleanRpgEventDispatcher::handleResizedEvent(const sf::Event& event) {
  getApp().setBackgroundColor(rng.randomColor());
  std::cout << "Handling resized event." << std::endl;
  std::cout << "  width: " << event.size.width
            << ", height: " << event.size.height << std::endl;
}

void CleanRpgEventDispatcher::handleLostFocusEvent(const sf::Event& event) {
  getApp().setBackgroundColor(rng.randomColor());
  std::cout << "Handling lost focus event." << std::endl;
}

void CleanRpgEventDispatcher::handleGainedFocusEvent(const sf::Event& event) {
  getApp().setBackgroundColor(rng.randomColor());
  std::cout << "Handling gained focus event." << std::endl;
}

void CleanRpgEventDispatcher::handleTextEnteredEvent(const sf::Event& event) {
  std::cout << "Handling text entered event." << std::endl;
  if (event.text.unicode < 128) {
    std::cout << "  ASCII code: " << static_cast<char>(event.text.unicode)
              << std::endl;
  }
}

void CleanRpgEventDispatcher::handleKeyPressedEvent(const sf::Event& event) {
  std::cout << "Handling key pressed event." << std::endl;
  std::cout << "  key code: " << event.key.code << std::endl;
}

void CleanRpgEventDispatcher::handleKeyReleasedEvent(const sf::Event& event) {
  std::cout << "Handling key released event." << std::endl;
  std::cout << "  key code: " << event.key.code << std::endl;
}

void CleanRpgEventDispatcher::handleMouseWheelScrolledEvent(
    const sf::Event& event) {
  std::cout << "Handling mouse wheel scrolled event." << std::endl;
}

void CleanRpgEventDispatcher::handleMouseButtonPressedEvent(
    const sf::Event& event) {
  std::cout << "Handling mouse button pressed event." << std::endl;
}

void CleanRpgEventDispatcher::handleMouseButtonReleasedEvent(
    const sf::Event& event) {
  std::cout << "Handling mouse button released event." << std::endl;
}

void CleanRpgEventDispatcher::handleMouseMovedEvent(const sf::Event& event) {
  getApp().moveHead(static_cast<float>(event.mouseMove.x),
                    static_cast<float>(event.mouseMove.y));
}

void CleanRpgEventDispatcher::handleMouseEnteredEvent(const sf::Event& event) {
  getApp().setBackgroundColor(rng.randomColor());
  std::cout << "Handling mouse entered event." << std::endl;
}

void CleanRpgEventDispatcher::handleMouseLeftEvent(const sf::Event& event) {
  getApp().setBackgroundColor(rng.randomColor());
  std::cout << "Handling mouse left event." << std::endl;
}

void CleanRpgEventDispatcher::handleUnknownEvent(const sf::Event& event) {
  std::cout << "Handling unknown event." << std::endl;
}

} // namespace cr
