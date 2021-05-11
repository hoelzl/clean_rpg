// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_CLEAN_RPG_APP_HPP
#define CLEAN_RPG_CLEAN_RPG_APP_HPP

#include "app/app.hpp"

namespace cr {
class CleanRpgEventDispatcher;

class CleanRpgApp : public cg::App<CleanRpgApp> {
public:
  using cg::App<CleanRpgApp>::App;

  void moveHead(float newX, float newY) {
    sf::Vector2<unsigned int> windowSize{getMainWindow().getSize()};
    sf::Rect<float>           spriteBounds{sprite->getLocalBounds()};
    sprite->setPosition(
        convertCoordinate(newX, static_cast<float>(windowSize.x) -
                                    spriteBounds.width),
        convertCoordinate(newY, static_cast<float>(windowSize.y) -
                                    spriteBounds.height));
  }

protected:
  void loadResources() override;
  void renderNextFrame() override;

private:
  sf::Sprite* sprite{};

  static float convertCoordinate(float coord, float max = 600.f) {
    return std::clamp(coord, 0.f, max);
  }
};
} // namespace cr

#endif // CLEAN_RPG_CLEAN_RPG_APP_HPP
