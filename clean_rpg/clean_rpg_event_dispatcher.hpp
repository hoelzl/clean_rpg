// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_CLEAN_RPG_EVENT_DISPATCHER_HPP
#define CLEAN_RPG_CLEAN_RPG_EVENT_DISPATCHER_HPP

#include "app/event_dispatcher.hpp"
#include "clean_rpg_app.hpp"
#include "util/random_number_generator.hpp"

namespace cr {

class CleanRpgEventDispatcher : public cg::EventDispatcher<cr::CleanRpgApp> {
public:
  using cg::EventDispatcher<cr::CleanRpgApp>::EventDispatcher;

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

} // namespace cr
#endif // CLEAN_RPG_CLEAN_RPG_EVENT_DISPATCHER_HPP
