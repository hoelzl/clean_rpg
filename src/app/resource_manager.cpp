// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "resource_manager.hpp"

namespace cr {

sf::Color ResourceManager::randomColor() {
  return sf::Color{randomColorValue(), randomColorValue(), randomColorValue()};
}

void      ResourceManager::loadResources() {}

sf::Uint8 ResourceManager::randomColorValue() {
  return static_cast<sf::Uint8>(random_color_distribution(random_engine));
}

} // namespace cr
