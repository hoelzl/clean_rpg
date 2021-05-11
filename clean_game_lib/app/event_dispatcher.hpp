// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_APP_EVENT_DISPATCHER_HPP
#define CLEAN_RPG_APP_EVENT_DISPATCHER_HPP

#include "SFML/Window/Event.hpp"
#include "resource_manager.hpp"

namespace cg {

class EventDispatcherBase {
public:
  void dispatchEvent(const sf::Event& event);

protected:
  virtual void handleCloseEvent(const sf::Event& event);
  virtual void handleResizedEvent(const sf::Event& event);
  virtual void handleLostFocusEvent(const sf::Event& event);
  virtual void handleGainedFocusEvent(const sf::Event& event);
  virtual void handleTextEnteredEvent(const sf::Event& event);
  virtual void handleKeyPressedEvent(const sf::Event& event);
  virtual void handleKeyReleasedEvent(const sf::Event& event);
  virtual void handleMouseWheelScrolledEvent(const sf::Event& event);
  virtual void handleMouseButtonPressedEvent(const sf::Event& event);
  virtual void handleMouseButtonReleasedEvent(const sf::Event& event);
  virtual void handleMouseMovedEvent(const sf::Event& event);
  virtual void handleMouseEnteredEvent(const sf::Event& event);
  virtual void handleMouseLeftEvent(const sf::Event& event);
  virtual void handleUnknownEvent(const sf::Event& event);

  bool isInitialized{true};
};

template <typename AppT>
class EventDispatcher : public EventDispatcherBase {
public:
  EventDispatcher() { isInitialized = false; }

  void setApp(AppT* newApp) {
    app           = newApp;
    isInitialized = true;
  }

  AppT* getApp() { return app; }

protected:
  void handleCloseEvent(const sf::Event& event) override { getApp()->close(); }

private:
  AppT* app;
};

} // namespace cg
#endif // CLEAN_RPG_APP_EVENT_DISPATCHER_HPP
