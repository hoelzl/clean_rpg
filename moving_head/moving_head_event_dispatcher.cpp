// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "moving_head_event_dispatcher.hpp"
#include <iostream>

namespace mh {

void MovingHeadEventDispatcher::handleCloseEvent(const sf::Event& event) {
  std::cout << "Closing application." << std::endl;
  EventDispatcher<mh::MovingHeadApp>::handleCloseEvent(event);
}

void MovingHeadEventDispatcher::handleResizedEvent(const sf::Event& event) {
  getApp()->setBackgroundColor(rng.randomColor());
  std::cout << "Handling resized event." << std::endl;
  std::cout << "  width: " << event.size.width
            << ", height: " << event.size.height << std::endl;
}

void MovingHeadEventDispatcher::handleLostFocusEvent(const sf::Event& event) {
  getApp()->setBackgroundColor(rng.randomColor());
  std::cout << "Handling lost focus event." << std::endl;
}

void MovingHeadEventDispatcher::handleGainedFocusEvent(const sf::Event& event) {
  getApp()->setBackgroundColor(rng.randomColor());
  std::cout << "Handling gained focus event." << std::endl;
}

void MovingHeadEventDispatcher::handleTextEnteredEvent(const sf::Event& event) {
  std::cout << "Handling text entered event." << std::endl;
  if (event.text.unicode < 128) {
    std::cout << "  ASCII code: " << static_cast<char>(event.text.unicode)
              << std::endl;
  }
}

void MovingHeadEventDispatcher::handleKeyPressedEvent(const sf::Event& event) {
  std::cout << "Handling key pressed event." << std::endl;
  std::cout << "  key code: " << event.key.code << std::endl;
}

void MovingHeadEventDispatcher::handleKeyReleasedEvent(const sf::Event& event) {
  std::cout << "Handling key released event." << std::endl;
  std::cout << "  key code: " << event.key.code << std::endl;
}

void MovingHeadEventDispatcher::handleMouseWheelScrolledEvent(
    const sf::Event& event) {
  std::cout << "Handling mouse wheel scrolled event." << std::endl;
}

void MovingHeadEventDispatcher::handleMouseButtonPressedEvent(
    const sf::Event& event) {
  std::cout << "Handling mouse button pressed event." << std::endl;
}

void MovingHeadEventDispatcher::handleMouseButtonReleasedEvent(
    const sf::Event& event) {
  std::cout << "Handling mouse button released event." << std::endl;
}

void MovingHeadEventDispatcher::handleMouseMovedEvent(const sf::Event& event) {
  getApp()->moveHead(static_cast<float>(event.mouseMove.x),
                     static_cast<float>(event.mouseMove.y));
}

void MovingHeadEventDispatcher::handleMouseEnteredEvent(
    const sf::Event& event) {
  getApp()->setBackgroundColor(rng.randomColor());
  std::cout << "Handling mouse entered event." << std::endl;
}

void MovingHeadEventDispatcher::handleMouseLeftEvent(const sf::Event& event) {
  getApp()->setBackgroundColor(rng.randomColor());
  std::cout << "Handling mouse left event." << std::endl;
}

void MovingHeadEventDispatcher::handleUnknownEvent(const sf::Event& event) {
  std::cout << "Handling unknown event." << std::endl;
}

} // namespace mh
