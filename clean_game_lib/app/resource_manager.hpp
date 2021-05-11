// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_APP_RESOURCE_MANAGER_HPP
#define CLEAN_RPG_APP_RESOURCE_MANAGER_HPP

#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <filesystem>
#include <map>
#include <optional>

namespace cg {

class ResourceManager {
public:
  [[nodiscard]] static std::filesystem::path getImgPath();
  [[nodiscard]] static std::filesystem::path getFontPath();

  ResourceManager& addTexture(const std::string& name,
                              const std::string& relative_path);
  ResourceManager& addSprite(const std::string& name,
                             const std::string& relative_texture_path,
                             float x = 0.0, float y = 0.0);
  ResourceManager& addFont(const std::string& name,
                           const std::string& relative_path);
  sf::Texture&     getTexture(const std::string& name);
  sf::Sprite&      getSprite(const std::string& name);
  sf::Font&        getFont(const std::string& name);

private:
  std::map<std::string, sf::Texture> textures{};
  std::map<std::string, sf::Sprite>  sprites{};
  std::map<std::string, sf::Font>    fonts{};

  static std::optional<sf::Texture>
  loadTexture(const std::string& relative_path);
};

} // namespace cg

#endif // CLEAN_RPG_APP_RESOURCE_MANAGER_HPP
