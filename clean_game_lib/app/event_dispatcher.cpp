// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "event_dispatcher.hpp"
#include "app.hpp"
#include <iostream>

namespace cg {

void EventDispatcherBase::dispatchEvent(const sf::Event& event) {
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
  // Other event types
  default:
    handleUnknownEvent(event);
    break;
  }
}

void EventDispatcherBase::handleCloseEvent(const sf::Event& event) {}
void EventDispatcherBase::handleResizedEvent(const sf::Event& event) {}
void EventDispatcherBase::handleLostFocusEvent(const sf::Event& event) {}
void EventDispatcherBase::handleGainedFocusEvent(const sf::Event& event) {}
void EventDispatcherBase::handleTextEnteredEvent(const sf::Event& event) {}
void EventDispatcherBase::handleKeyPressedEvent(const sf::Event& event) {}
void EventDispatcherBase::handleKeyReleasedEvent(const sf::Event& event) {}
void EventDispatcherBase::handleMouseWheelScrolledEvent(
    const sf::Event& event) {}
void EventDispatcherBase::handleMouseButtonPressedEvent(
    const sf::Event& event) {}
void EventDispatcherBase::handleMouseButtonReleasedEvent(
    const sf::Event& event) {}
void EventDispatcherBase::handleMouseMovedEvent(const sf::Event& event) {}
void EventDispatcherBase::handleMouseEnteredEvent(const sf::Event& event) {}
void EventDispatcherBase::handleMouseLeftEvent(const sf::Event& event) {}
void EventDispatcherBase::handleUnknownEvent(const sf::Event& event) {}

} // namespace cg
