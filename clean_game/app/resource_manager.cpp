// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "resource_manager.hpp"
#include <filesystem>
#include <iostream>
#include <optional>

namespace cg {

using path = std::filesystem::path;

path ResourceManager::getDataPath() {
  path currentPath{std::filesystem::current_path()};
  path img_path{currentPath / "img"};
  if (exists(img_path)) {
    return img_path;
  } else {
    path parentImgPath{currentPath.parent_path() / "img"};
    if (exists(parentImgPath)) {
      return parentImgPath;
    }
  }
  return currentPath;
}

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

std::optional<sf::Texture>
ResourceManager::loadTexture(const std::string& relative_path) {
  std::filesystem::path imagePath{getDataPath() / relative_path};
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

} // namespace cg
