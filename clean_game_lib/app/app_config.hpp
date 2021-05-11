// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_GAME_LIB_APP_APP_CONFIG_HPP
#define CLEAN_GAME_LIB_APP_APP_CONFIG_HPP

#include "event_dispatcher.hpp"

namespace cg {

template <typename AppT>
class AppConfig {
public:
  std::unique_ptr<EventDispatcher<AppT>> eventDispatcher{};
  unsigned int                           width{800};
  unsigned int                           height{600};
  std::string                            title{"Clean Game"};
};

template <typename AppT, typename AppConfigT, typename BuilderT>
class AppConfigBuilder : public AppConfig<AppT> {
public:
  using SelfT = AppConfigBuilder<AppT, AppConfigT, BuilderT>;

  SelfT& setEventDispatcher(std::unique_ptr<EventDispatcher<AppT>> ed) {
    config.eventDispatcher = std::move(ed);
    return static_cast<SelfT&>(*this);
  }

  SelfT& setWidth(int w) {
    config.width = w;
    return static_cast<SelfT&>(*this);
  }

  SelfT& setHeight(int h) {
    config.height = h;
    return static_cast<SelfT&>(*this);
  }

  SelfT& setTitle(const char* t) {
    config.title = t;
    return static_cast<SelfT&>(*this);
  }

  AppConfigT getConfig() { return std::move(config); }

private:
  AppConfigT config{};
};

template <typename AppT>
class DefaultAppConfigBuilder
    : public AppConfigBuilder<AppT, AppConfig<AppT>,
                              AppConfigBuilder<AppT, AppConfig<AppT>,
                                               DefaultAppConfigBuilder<AppT>>> {
};

} // namespace cg
#endif // CLEAN_GAME_LIB_APP_APP_CONFIG_HPP
