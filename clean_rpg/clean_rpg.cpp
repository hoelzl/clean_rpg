// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "app/app.hpp"
#include "clean_rpg_app.hpp"
#include "clean_rpg_app_config.hpp"
#include "clean_rpg_config.hpp"
#include "clean_rpg_event_dispatcher.hpp"
#include <iostream>

void printProgramInfo() {
  std::cout << "Clean RPG Version " << CleanRpgVersion::version_string()
            << " is up and running!" << std::endl;
}

int main() {
  printProgramInfo();
  std::unique_ptr<cg::AppConfig<cr::CleanRpgApp>> ac{
      std::make_unique<cr::CleanRpgAppConfig>()};
  cr::CleanRpgApp app{std::move(ac)};
  app.init();
  return app.runEventLoop();
}
