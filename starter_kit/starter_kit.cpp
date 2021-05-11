// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "app/app.hpp"
#include "starter_kit_app.hpp"
#include "starter_kit_config.hpp"
#include "starter_kit_event_dispatcher.hpp"
#include <iostream>
#include <string>

using namespace std::literals::string_literals;

void printProgramInfo() {
  std::cout << "Moving Head example Version "
            << StarterKitVersion::version_string() << " is up and running!"
            << std::endl;
}

void createConfiguration(
    cg::DefaultAppConfigBuilder<sk::StarterKitApp>& builder) {
  const std::string versionString = StarterKitVersion::version_string();
  auto eventDispatcher{std::make_unique<sk::StarterKitEventDispatcher>()};
  builder.setEventDispatcher(std::move(eventDispatcher))
      .setHeight(800)
      .setWidth(1200)
      .setTitle("Starter Kit (Version "s + versionString + ")"s);
}

int main() {
  printProgramInfo();
  cg::DefaultAppConfigBuilder<sk::StarterKitApp> builder{};
  createConfiguration(builder);
  std::unique_ptr<sk::StarterKitApp> app{
      sk::StarterKitApp::create(builder.getConfig())};
  return app->runEventLoop();
}
