// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_APP_APP_HPP
#define CLEAN_RPG_APP_APP_HPP

#include "SFML/Graphics.hpp"
#include "event_dispatcher.hpp"
#include "resource_manager.hpp"
#include <random>
#include <string>

namespace cg {

class App;

template <typename EventDispatcherT> struct AppConfig {
  unsigned int width  = 800;
  unsigned int height = 600;
  std::string  title  = "Clean Game";

  std::unique_ptr<EventDispatcherT> createEventDispatcher(App& app) {
    return std::make_unique<EventDispatcherT>(app);
  };
};

class App {
public:
  template <typename EventDispatcherT>
  explicit App(AppConfig<EventDispatcherT> ac)
      : mainWindow{sf::VideoMode{ac.width, ac.height}, ac.title},
        eventDispatcher{ac.createEventDispatcher(*this)} {}

  virtual void init();

  sf::RenderWindow& getMainWindow() { return mainWindow; };
  ResourceManager&  getResourceManager() { return resourceManager; }

  sf::Color getBackgroundColor() const { return backgroundColor; }
  void      setBackgroundColor(sf::Color color) { backgroundColor = color; }

  void moveHead(float newX, float newY);

  int runEventLoop();

  void close();

protected:
  virtual void setWindowParameters();
  virtual void loadResources();

  virtual void renderNextFrame();

private:
  void processPendingEvents();
  void dispatchEvent(const sf::Event& event);

  bool                             isInitialized{false};
  std::unique_ptr<EventDispatcher> eventDispatcher{};
  ResourceManager                  resourceManager{};
  RandomNumberGenerator            rng{};

  sf::RenderWindow mainWindow;
  sf::Color        backgroundColor = sf::Color::Black;
};
} // namespace cg

#endif // CLEAN_RPG_APP_APP_HPP
