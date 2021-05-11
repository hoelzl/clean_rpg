// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_CLEAN_RPG_APP_CONFIG_HPP
#define CLEAN_RPG_CLEAN_RPG_APP_CONFIG_HPP

#include "app/app.hpp"
#include "clean_rpg_event_dispatcher.hpp"

namespace cr {
class CleanRpgApp;

struct CleanRpgAppConfig : public cg::AppConfig<CleanRpgApp> {
  std::unique_ptr<cg::EventDispatcher<CleanRpgApp>>
  createEventDispatcher(CleanRpgApp& app) override;
};
} // namespace cr

#endif // CLEAN_RPG_CLEAN_RPG_APP_CONFIG_HPP
