// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_SRC_APP_RESOURCE_MANAGER_HPP
#define CLEAN_RPG_SRC_APP_RESOURCE_MANAGER_HPP

#include "SFML/Graphics/Color.hpp"
#include <random>

namespace cr {

class ResourceManager {
public:
  sf::Color randomColor();

  void      loadResources();

private:
  sf::Uint8                                     randomColorValue();

  std::random_device                            rd{};
  std::default_random_engine                    random_engine{rd()};
  std::uniform_int_distribution<unsigned short> random_color_distribution{0,
                                                                          255};
};

} // namespace cr

#endif // CLEAN_RPG_SRC_APP_RESOURCE_MANAGER_HPP
