// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "default_clean_rpg_builder.hpp"
#include "clean_rpg_event_dispatcher.hpp"

namespace cr {
std::unique_ptr<cg::DefaultAppConfigBuilder<CleanRpgApp>>
createDefaultBuilder() {
  auto builder{std::make_unique<cg::DefaultAppConfigBuilder<CleanRpgApp>>()};
  auto eventDispatcher{std::make_unique<CleanRpgEventDispatcher>()};
  builder->setEventDispatcher(std::move(eventDispatcher))
      .setHeight(800)
      .setWidth(1200)
      .setTitle("Clean RPG (Version " + CleanRpgVersion::version_string() +
                ")");
  return builder;
}
} // namespace cr
