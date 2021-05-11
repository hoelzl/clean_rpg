// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "clean_rpg_app.hpp"
#include "clean_rpg_config.hpp"

void CleanRpgApp::loadResources() {
  getResourceManager().addSprite("head", CLEAN_RPG_IMG_DIR "/head.png", 300.f,
                                 100.f);
  sprite = &getResourceManager().getSprite("head");
}
void CleanRpgApp::renderNextFrame() {
  getMainWindow().clear(getBackgroundColor());
  if (sprite) {
    getMainWindow().draw(*sprite);
  }
  getMainWindow().display();
}
