// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "app/app.hpp"
#include "clean_rpg_config.hpp"
#include <iostream>

void printProgramInfo() {
  std::cout << "Clean RPG Version " << CleanRpgVersion::version_string()
            << " is up and running!" << std::endl;
}

int main() {
  printProgramInfo();
  cr::App app{};
  return app.runEventLoop();
}
