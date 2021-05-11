// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "clean_rpg_app_config.hpp"

namespace cr {
std::unique_ptr<cg::EventDispatcher<CleanRpgApp>>
CleanRpgAppConfig::createEventDispatcher(CleanRpgApp& app) {
  return std::make_unique<CleanRpgEventDispatcher>(app);
}
} // namespace cr
