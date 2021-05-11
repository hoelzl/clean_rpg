// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_APP_RANDOM_NUMBER_GENERATOR_HPP
#define CLEAN_RPG_APP_RANDOM_NUMBER_GENERATOR_HPP

#include "SFML/Graphics/Color.hpp"
#include <random>

class RandomNumberGenerator {
public:
  sf::Color randomColor();

private:
  sf::Uint8 randomColorValue();

  using UniformColorDistribution =
      std::uniform_int_distribution<unsigned short>;

  std::random_device         rd{};
  std::default_random_engine random_engine{rd()};
  UniformColorDistribution   randomColorDistribution{0, 255};
};

#endif // CLEAN_RPG_APP_RANDOM_NUMBER_GENERATOR_HPP
