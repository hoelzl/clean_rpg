// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "app/app.hpp"
#include "clean_rpg_app.hpp"
#include "clean_rpg_config.hpp"
#include <iostream>

void printProgramInfo() {
  std::cout << "Clean RPG Version " << CleanRpgVersion::version_string()
            << " is up and running!" << std::endl;
}

int main() {
  printProgramInfo();
  cg::AppConfig<cg::EventDispatcher> ac{};
  CleanRpgApp                        app{ac};
  app.init();
  return app.runEventLoop();
}
