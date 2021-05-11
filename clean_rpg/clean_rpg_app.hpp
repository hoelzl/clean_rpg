// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_CLEAN_RPG_APP_HPP
#define CLEAN_RPG_CLEAN_RPG_APP_HPP

#include "app/app.hpp"

class CleanRpgApp : public cg::App {
public:
  using cg::App::App;

protected:
  void loadResources() override;
  void renderNextFrame() override;

private:
  sf::Sprite* sprite{};
};

#endif // CLEAN_RPG_CLEAN_RPG_APP_HPP
