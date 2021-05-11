// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef MOVING_HEAD_MOVING_HEAD_APP_HPP
#define MOVING_HEAD_MOVING_HEAD_APP_HPP

#include "app/app.hpp"

namespace mh {
class MovingHeadApp : public cg::App<MovingHeadApp> {
public:
  using cg::App<MovingHeadApp>::App;

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
} // namespace mh

#endif // MOVING_HEAD_MOVING_HEAD_APP_HPP
