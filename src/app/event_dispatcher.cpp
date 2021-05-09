// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "event_dispatcher.hpp"
#include "app.hpp"
#include <iostream>

namespace cr {
void EventDispatcher::dispatchEvent(const sf::Event &event) {
  switch (event.type) {
  case sf::Event::Closed:
    handleCloseEvent(event);
    break;
  case sf::Event::Resized:
    handleResizedEvent(event);
    break;
  case sf::Event::LostFocus:
    handleLostFocusEvent(event);
    break;
  case sf::Event::GainedFocus:
    handleGainedFocusEvent(event);
    break;
  case sf::Event::TextEntered:
    handleTextEnteredEvent(event);
    break;
  case sf::Event::KeyPressed:
    handleKeyPressedEvent(event);
    break;
  case sf::Event::KeyReleased:
    handleKeyReleasedEvent(event);
    break;
  case sf::Event::MouseWheelScrolled:
    handleMouseWheelScrolledEvent(event);
    break;
  case sf::Event::MouseButtonPressed:
    handleMouseButtonPressedEvent(event);
    break;
  case sf::Event::MouseButtonReleased:
    handleMouseButtonReleasedEvent(event);
    break;
  case sf::Event::MouseMoved:
    handleMouseMovedEvent(event);
    break;
  case sf::Event::MouseEntered:
    handleMouseEnteredEvent(event);
    break;
  case sf::Event::MouseLeft:
    handleMouseLeftEvent(event);
    break;
    // Joystick events currently not supported.
  default:
    handleUnknownEvent(event);
    break;
  }
}

void EventDispatcher::handleCloseEvent(const sf::Event &event) { app.close(); }

void EventDispatcher::handleResizedEvent(const sf::Event &event) {
  app.setBackgroundColor(resourceManager.randomColor());
  std::cout << "Handling resized event." << std::endl;
  std::cout << "  width: " << event.size.width
            << ", height: " << event.size.height << std::endl;
}

void EventDispatcher::handleLostFocusEvent(const sf::Event &event) {
  app.setBackgroundColor(resourceManager.randomColor());
  std::cout << "Handling lost focus event." << std::endl;
}

void EventDispatcher::handleGainedFocusEvent(const sf::Event &event) {
  app.setBackgroundColor(resourceManager.randomColor());
  std::cout << "Handling gained focus event." << std::endl;
}

void EventDispatcher::handleTextEnteredEvent(const sf::Event &event) {
  std::cout << "Handling text entered event." << std::endl;
  if (event.text.unicode < 128) {
    std::cout << "  ASCII code: " << static_cast<char>(event.text.unicode)
              << std::endl;
  }
}

void EventDispatcher::handleKeyPressedEvent(const sf::Event &event) {
  std::cout << "Handling key pressed event." << std::endl;
  std::cout << "  key code: " << event.key.code << std::endl;
}

void EventDispatcher::handleKeyReleasedEvent(const sf::Event &event) {
  std::cout << "Handling key released event." << std::endl;
  std::cout << "  key code: " << event.key.code << std::endl;
}

void EventDispatcher::handleMouseWheelScrolledEvent(const sf::Event &event) {
  std::cout << "Handling mouse wheel scrolled event." << std::endl;
}

void EventDispatcher::handleMouseButtonPressedEvent(const sf::Event &event) {
  std::cout << "Handling mouse button pressed event." << std::endl;
}

void EventDispatcher::handleMouseButtonReleasedEvent(const sf::Event &event) {
  std::cout << "Handling mouse button released event." << std::endl;
}

void EventDispatcher::handleMouseMovedEvent(const sf::Event &event) {
  // Disable reporting of mouse move events for now, since they tend to
  // crowd out all other events.
  //  std::cout << "Handling mouse moved event." << std::endl;
  //  std::cout << "  mouse x: " << event.mouseMove.x
  //            << ", mouse y: " << event.mouseMove.y << std::endl;
}

void EventDispatcher::handleMouseEnteredEvent(const sf::Event &event) {
  app.setBackgroundColor(resourceManager.randomColor());
  std::cout << "Handling mouse entered event." << std::endl;
}

void EventDispatcher::handleMouseLeftEvent(const sf::Event &event) {
  app.setBackgroundColor(resourceManager.randomColor());
  std::cout << "Handling mouse left event." << std::endl;
}

void EventDispatcher::handleUnknownEvent(const sf::Event &event) {
  std::cout << "Handling unknown event." << std::endl;
}

EventDispatcher::EventDispatcher(App &app)
    : app{app}, resourceManager{app.getResourceManager()} {}

} // namespace cr
