// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "random_number_generator.hpp"

sf::Color RandomNumberGenerator::randomColor() {
  return sf::Color{randomColorValue(), randomColorValue(), randomColorValue()};
}

sf::Uint8 RandomNumberGenerator::randomColorValue() {
  return static_cast<sf::Uint8>(randomColorDistribution(random_engine));
}
