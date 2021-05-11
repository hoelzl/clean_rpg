// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "app/app.hpp"
#include "clean_rpg_app.hpp"
#include "clean_rpg_config.hpp"
#include "clean_rpg_event_dispatcher.hpp"
#include <iostream>

void printProgramInfo() {
  std::cout << "Clean RPG Version " << CleanRpgVersion::version_string()
            << " is up and running!" << std::endl;
}

void buildConfiguration(cg::DefaultAppConfigBuilder<cr::CleanRpgApp>& builder) {
  builder.setEventDispatcher(std::make_unique<cr::CleanRpgEventDispatcher>())
      .setHeight(800)
      .setWidth(1200)
      .setTitle("Clean RPG");
}
int main() {
  printProgramInfo();
  cg::DefaultAppConfigBuilder<cr::CleanRpgApp> builder{};
  buildConfiguration(builder);
  std::unique_ptr<cr::CleanRpgApp> app{
      cr::CleanRpgApp::create(builder.getConfig())};
  return app->runEventLoop();
}
