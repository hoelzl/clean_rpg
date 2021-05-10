// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_APP_RESOURCE_MANAGER_HPP
#define CLEAN_RPG_APP_RESOURCE_MANAGER_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <filesystem>
#include <map>
#include <optional>

namespace cr {

class ResourceManager {
public:
  [[nodiscard]] static std::filesystem::path getDataPath();

  ResourceManager& addTexture(const std::string& name,
                              const std::string& relative_path);
  ResourceManager& addSprite(const std::string& name,
                             const std::string& relative_texture_path,
                             float x = 0.0, float y = 0.0);
  sf::Texture&     getTexture(const std::string& name);
  sf::Sprite&      getSprite(const std::string& name);

private:
  std::map<std::string, sf::Texture> textures{};
  std::map<std::string, sf::Sprite>  sprites{};

  static std::optional<sf::Texture>
  loadTexture(const std::string& relative_path);
};

} // namespace cr

#endif // CLEAN_RPG_APP_RESOURCE_MANAGER_HPP
