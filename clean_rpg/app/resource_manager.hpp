// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_SRC_APP_RESOURCE_MANAGER_HPP
#define CLEAN_RPG_SRC_APP_RESOURCE_MANAGER_HPP

#include "SFML/Graphics/Color.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <filesystem>
#include <random>

namespace cr {

class ResourceManager {
public:
  sf::Color randomColor();

  [[nodiscard]] static std::filesystem::path getDataPath();

  void loadResources();

  sf::Sprite &getSprite() { return sprite; }

private:
  sf::Texture texture{};
  sf::Sprite  sprite{};

  sf::Uint8 randomColorValue();

  using UniformColorDistribution =
      std::uniform_int_distribution<unsigned short>;

  std::random_device         rd{};
  std::default_random_engine random_engine{rd()};
  UniformColorDistribution   randomColorDistribution{0, 255};
};

} // namespace cr

#endif // CLEAN_RPG_SRC_APP_RESOURCE_MANAGER_HPP
