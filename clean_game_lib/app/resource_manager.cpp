// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "resource_manager.hpp"
#include "clean_game_lib_config.hpp"
#include <filesystem>
#include <iostream>
#include <optional>

namespace cg {

using path = std::filesystem::path;

path ResourceManager::getImgPath() { return path{CLEAN_GAME_LIB_IMG_DIR}; }

path ResourceManager::getFontPath() { return path{CLEAN_GAME_LIB_FONT_DIR}; }

ResourceManager& ResourceManager::addTexture(const std::string& name,
                                             const std::string& relative_path) {
  std::optional<sf::Texture> texture{loadTexture(relative_path)};
  if (!texture) {
    std::cerr << "Could not load texture " << relative_path << std::endl;
  } else {
    textures[name] = *texture;
  }
  return *this;
}

ResourceManager&
ResourceManager::addSprite(const std::string& name,
                           const std::string& relative_texture_path,
                           float x /*= 0.0*/, float y /*= 0.0*/) {
  std::optional<sf::Texture> texture{loadTexture(relative_texture_path)};
  if (!texture) {
    std::cerr << "Could not load texture " << relative_texture_path
              << std::endl;
  } else {
    textures[name] = *texture;
    sf::Sprite sprite{textures[name]};
    sprite.setPosition(x, y);
    sprites[name] = sprite;
  }
  return *this;
}

ResourceManager& ResourceManager::addFont(const std::string& name,
                                          const std::string& relative_path) {
  path fontPath{getFontPath() / relative_path};
  std::cout << "Loading font from " << fontPath << std::endl;
  sf::Font font;
  if (!font.loadFromFile(fontPath.string())) {
    std::cerr << "Could not load font!" << std::endl;
  } else {
    fonts[name] = font;
  }
  return *this;
}

std::optional<sf::Texture>
ResourceManager::loadTexture(const std::string& relative_path) {
  path imagePath{getImgPath() / relative_path};
  std::cout << "Loading texture from " << imagePath << std::endl;
  sf::Texture texture{};
  if (!texture.loadFromFile(imagePath.string())) {
    return std::nullopt;
  }
  return texture;
}

sf::Texture& ResourceManager::getTexture(const std::string& name) {
  return textures.at(name);
}

sf::Sprite& ResourceManager::getSprite(const std::string& name) {
  return sprites.at(name);
}
sf::Font& ResourceManager::getFont(const std::string& name) {
  return fonts.at(name);
}
} // namespace cg
