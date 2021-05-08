// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_SRC_WRAPPERS_VIDEO_MODE_HPP
#define CLEAN_RPG_SRC_WRAPPERS_VIDEO_MODE_HPP

#include "SFML/Window/VideoMode.hpp"
#include <vector>

namespace cr {

class video_mode : public sf::VideoMode {
private:
  static std::vector<video_mode> fullscreen_modes;

public:
  video_mode() : VideoMode{} {}

  video_mode(unsigned int mode_width, unsigned int mode_height,
             unsigned int mode_bits_per_pixel = 32)
      : VideoMode{mode_width, mode_height, mode_bits_per_pixel} {}

  video_mode(const sf::VideoMode &vm) // NOLINT(google-explicit-constructor)
      : video_mode{vm.width, vm.height, vm.bitsPerPixel} {}

  unsigned int &bits_per_pixel{bitsPerPixel};

  [[nodiscard]] bool is_valid() const { return isValid(); }

  static video_mode get_desktop_mode() { return video_mode{getDesktopMode()}; }

  static const std::vector<video_mode> &get_fullscreen_modes() {
    if (fullscreen_modes.empty()) {
      for (const sf::VideoMode &vm : getFullscreenModes()) {
        fullscreen_modes.emplace_back(vm);
      }
    }
    return fullscreen_modes;
  }
};

} // namespace cr

#endif // CLEAN_RPG_SRC_WRAPPERS_VIDEO_MODE_HPP
