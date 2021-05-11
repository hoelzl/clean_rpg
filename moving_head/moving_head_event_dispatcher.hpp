// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef MOVING_HEAD_MOVING_HEAD_EVENT_DISPATCHER_HPP
#define MOVING_HEAD_MOVING_HEAD_EVENT_DISPATCHER_HPP

#include "app/event_dispatcher.hpp"
#include "moving_head_app.hpp"
#include "util/random_number_generator.hpp"

namespace mh {
class MovingHeadEventDispatcher
    : public cg::EventDispatcher<mh::MovingHeadApp> {
public:
  using cg::EventDispatcher<mh::MovingHeadApp>::EventDispatcher;

protected:
  void handleCloseEvent(const sf::Event& event) override;
  void handleResizedEvent(const sf::Event& event) override;
  void handleLostFocusEvent(const sf::Event& event) override;
  void handleGainedFocusEvent(const sf::Event& event) override;
  void handleTextEnteredEvent(const sf::Event& event) override;
  void handleKeyPressedEvent(const sf::Event& event) override;
  void handleKeyReleasedEvent(const sf::Event& event) override;
  void handleMouseWheelScrolledEvent(const sf::Event& event) override;
  void handleMouseButtonPressedEvent(const sf::Event& event) override;
  void handleMouseButtonReleasedEvent(const sf::Event& event) override;
  void handleMouseMovedEvent(const sf::Event& event) override;
  void handleMouseEnteredEvent(const sf::Event& event) override;
  void handleMouseLeftEvent(const sf::Event& event) override;
  void handleUnknownEvent(const sf::Event& event) override;

private:
  RandomNumberGenerator rng{};
};
} // namespace mh

#endif // MOVING_HEAD_MOVING_HEAD_EVENT_DISPATCHER_HPP
