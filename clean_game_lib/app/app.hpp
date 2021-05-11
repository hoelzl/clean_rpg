// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_APP_APP_HPP
#define CLEAN_RPG_APP_APP_HPP

#include "SFML/Graphics.hpp"
#include "app/app_config.hpp"
#include "event_dispatcher.hpp"
#include "resource_manager.hpp"
#include "util/random_number_generator.hpp"
#include <cassert>
#include <string>

namespace cg {

template <typename DerivedT>
class App {
public:
  static std::unique_ptr<DerivedT> create(AppConfig<DerivedT> ac) {
    auto result{std::unique_ptr<DerivedT>{new DerivedT{ac}}};
    result->init();
    return result;
  }

  sf::RenderWindow& getMainWindow() { return mainWindow; };
  ResourceManager&  getResourceManager() { return resourceManager; }

  sf::Color getBackgroundColor() const { return backgroundColor; }
  void      setBackgroundColor(sf::Color color) { backgroundColor = color; }

  int  runEventLoop();
  void close();

protected:
  virtual void init() {
    assert(eventDispatcher);
    eventDispatcher->setApp(static_cast<DerivedT*>(this));
    setWindowParameters();
    loadResources();
    isInitialized = true;
  }

  virtual void setWindowParameters();
  virtual void loadResources();

  virtual void renderNextFrame();

private:
  explicit App(AppConfig<DerivedT>& ac)
      : eventDispatcher{std::move(ac.eventDispatcher)},
        mainWindow{sf::VideoMode{ac.width, ac.height}, ac.title} {}

  void processPendingEvents();
  void dispatchEvent(const sf::Event& event);

  bool isInitialized{false};

  std::unique_ptr<EventDispatcher<DerivedT>> eventDispatcher{};

  ResourceManager       resourceManager{};
  RandomNumberGenerator rng{};

  sf::RenderWindow mainWindow;
  sf::Color        backgroundColor = sf::Color::Black;
};

template <typename DerivedT>
int App<DerivedT>::runEventLoop() {
  assert(isInitialized);
  while (mainWindow.isOpen()) {
    processPendingEvents();
    renderNextFrame();
  }
  return 0;
}

template <typename DerivedT>
void App<DerivedT>::close() {
  mainWindow.close();
}

template <typename DerivedT>
void App<DerivedT>::setWindowParameters() {
  backgroundColor = rng.randomColor();
  mainWindow.setVerticalSyncEnabled(true);
}

template <typename DerivedT>
void App<DerivedT>::loadResources() {}

template <typename DerivedT>
void App<DerivedT>::renderNextFrame() {
  getMainWindow().clear(getBackgroundColor());
  getMainWindow().display();
}

template <typename DerivedT>
void App<DerivedT>::processPendingEvents() {
  sf::Event event{};
  while (mainWindow.pollEvent(event)) {
    dispatchEvent(event);
  }
}

template <typename DerivedT>
void App<DerivedT>::dispatchEvent(const sf::Event& event) {
  if (eventDispatcher) {
    eventDispatcher->dispatchEvent(event);
  }
}

} // namespace cg

#endif // CLEAN_RPG_APP_APP_HPP
