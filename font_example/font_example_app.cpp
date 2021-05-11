// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "font_example_app.hpp"
#include "font_example_config.hpp"

namespace fe {
void FontExampleApp::loadResources() {
  cg::ResourceManager& rm{getResourceManager()};
  rm.addFont("bungee", "Bungee-Regular.ttf")
      .addFont("bungee-outline", "BungeeOutline-Regular.ttf")
      .addFont("bungee-shade", "BungeeShade-Regular.ttf");
}
void FontExampleApp::init() {
  App::init();
  text.setFont(getResourceManager().getFont("bungee"));
  text.setString("Hello, world!");
  text.setCharacterSize(90);
  text.setPosition(200, 300);
  text.setFillColor(sf::Color::Black);
  text.setOutlineColor(sf::Color::White);
  text.setOutlineThickness(6.f);
}
void FontExampleApp::renderNextFrame() {
  getMainWindow().clear(getBackgroundColor());
  getMainWindow().draw(text);
  getMainWindow().display();
}
} // namespace fe
