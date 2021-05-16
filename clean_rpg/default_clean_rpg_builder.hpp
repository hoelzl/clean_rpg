// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_DEFAULT_CLEAN_RPG_BUILDER_HPP
#define CLEAN_RPG_DEFAULT_CLEAN_RPG_BUILDER_HPP

#include "app/app_config.hpp"
#include "clean_rpg_app.hpp"
#include <memory>

namespace cr {
std::unique_ptr<cg::DefaultAppConfigBuilder<CleanRpgApp>>
createDefaultBuilder();

} // namespace cr

#endif // CLEAN_RPG_DEFAULT_CLEAN_RPG_BUILDER_HPP
