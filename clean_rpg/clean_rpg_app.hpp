// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_CLEAN_RPG_APP_HPP
#define CLEAN_RPG_CLEAN_RPG_APP_HPP

#include "app/app.hpp"

namespace cr {
class CleanRpgEventDispatcher;

class CleanRpgApp : public cg::App<CleanRpgApp> {
public:
  using cg::App<CleanRpgApp>::App;

protected:
  void loadResources() override;
  void renderNextFrame() override;

private:
  sf::Sprite* sprite{};
};
} // namespace cr

#endif // CLEAN_RPG_CLEAN_RPG_APP_HPP
