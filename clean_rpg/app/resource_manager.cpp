// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "resource_manager.hpp"
#include <filesystem>
#include <iostream>

namespace cr {

sf::Color ResourceManager::randomColor() {
  return sf::Color{randomColorValue(), randomColorValue(), randomColorValue()};
}

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

void ResourceManager::loadResources() {
  std::cout << "Loading resources from " << getDataPath() << std::endl;
  const std::string imagePath{(getDataPath() / "head.png").string()};
  if (!texture.loadFromFile(imagePath)) {
    std::cerr << "Could not load file 'head.png'!" << std::endl;
    return;
  }
  sprite.setTexture(texture);
  sprite.setPosition(300.0, 100.0);
}

sf::Uint8 ResourceManager::randomColorValue() {
  return static_cast<sf::Uint8>(randomColorDistribution(random_engine));
}

} // namespace cr
