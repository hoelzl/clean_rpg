// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "moving_head_app.hpp"
#include "moving_head_config.hpp"

namespace mh {
void MovingHeadApp::loadResources() {
  getResourceManager().addSprite("head", MOVING_HEAD_IMG_DIR "/head.png", 300.f,
                                 100.f);
  sprite = &getResourceManager().getSprite("head");
}

void MovingHeadApp::renderNextFrame() {
  getMainWindow().clear(getBackgroundColor());
  if (sprite) {
    getMainWindow().draw(*sprite);
  }
  getMainWindow().display();
}
} // namespace mh
