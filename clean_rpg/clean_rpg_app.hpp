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
    sprite->setPosition(convertCoordinate(newX, 450.f),
                        convertCoordinate(newY, 150.f));
  }

protected:
  void loadResources() override;
  void renderNextFrame() override;

private:
  sf::Sprite* sprite{};

  static float convertCoordinate(float coord, float max = 600.f) {
    return std::clamp(coord, 50.f, max);
  }
};
} // namespace cr

#endif // CLEAN_RPG_CLEAN_RPG_APP_HPP
