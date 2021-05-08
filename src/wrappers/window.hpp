// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_SRC_WRAPPERS_WINDOW_HPP
#define CLEAN_RPG_SRC_WRAPPERS_WINDOW_HPP

#include "SFML/Window.hpp"

namespace cr {

class window : public sf::Window {
public:
  using sf::Window::Window;

  [[nodiscard]] bool is_open() const { return isOpen(); }

  [[nodiscard]] const sf::ContextSettings &get_settings() const {
    return getSettings();
  }

  bool poll_event(sf::Event &event) { return pollEvent(event); }

  bool wait_event(sf::Event &event) { return waitEvent(event); }

  [[nodiscard]] sf::Vector2i get_position() const { return getPosition(); }

  void set_position(const sf::Vector2i &position) { setPosition(position); }

  [[nodiscard]] sf::Vector2u get_size() const { return getSize(); }

  void set_size(const sf::Vector2u &size) { setSize(size); }

  void set_title(const sf::String &title) { setTitle(title); }

  void set_icon(unsigned int width, unsigned int height,
                const sf::Uint8 *pixels) {
    setIcon(width, height, pixels);
  }

  void set_visible(bool visible) { setVisible(visible); }

  void set_vertical_sync_enabled(bool enabled) {
    setVerticalSyncEnabled(enabled);
  }

  void set_mouse_cursor_visible(bool visible) {
    setMouseCursorVisible(visible);
  }

  void set_mouse_cursor_grabbed(bool grabbed) {
    setMouseCursorGrabbed(grabbed);
  }

  void set_mouse_cursor(const sf::Cursor &cursor) { setMouseCursor(cursor); }

  void set_key_repeat_enabled(bool enabled) { setKeyRepeatEnabled(enabled); }

  void set_framerate_limit(unsigned int limit) { setFramerateLimit(limit); }

  void set_joystick_threshold(float threshold) {
    setJoystickThreshold(threshold);
  }

  bool set_active(bool active = true) { return setActive(active); }

  void request_focus() { requestFocus(); }

  [[nodiscard]] bool has_focus() const { return hasFocus(); }
};

} // namespace cr

#endif // CLEAN_RPG_SRC_WRAPPERS_WINDOW_HPP
