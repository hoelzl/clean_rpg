// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "app/app.hpp"
#include "starter_kit_app.hpp"
#include "starter_kit_config.hpp"
#include "starter_kit_event_dispatcher.hpp"
#include <iostream>

void printProgramInfo() {
  std::cout << "Moving Head example Version "
            << StarterKitVersion::version_string() << " is up and running!"
            << std::endl;
}

void buildConfiguration(
    cg::DefaultAppConfigBuilder<sk::StarterKitApp>& builder) {
  builder.setEventDispatcher(std::make_unique<sk::StarterKitEventDispatcher>())
      .setHeight(800)
      .setWidth(1200)
      .setTitle("Starter Kit");
}
int main() {
  printProgramInfo();
  cg::DefaultAppConfigBuilder<sk::StarterKitApp> builder{};
  buildConfiguration(builder);
  std::unique_ptr<sk::StarterKitApp> app{
      sk::StarterKitApp::create(builder.getConfig())};
  return app->runEventLoop();
}
