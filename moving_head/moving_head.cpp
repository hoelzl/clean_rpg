// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "app/app.hpp"
#include "moving_head_app.hpp"
#include "moving_head_config.hpp"
#include "moving_head_event_dispatcher.hpp"
#include <iostream>

using namespace std::literals::string_literals;

void printProgramInfo() {
  std::cout << "Moving Head example Version "
            << MovingHeadVersion::version_string() << " is up and running!"
            << std::endl;
}

void createConfiguration(
    cg::DefaultAppConfigBuilder<mh::MovingHeadApp>& builder) {
  const std::string versionString{MovingHeadVersion::version_string()};
  auto eventDispatcher{std::make_unique<mh::MovingHeadEventDispatcher>()};
  builder.setEventDispatcher(std::move(eventDispatcher))
      .setHeight(800)
      .setWidth(1200)
      .setTitle("Moving Head (Version "s + versionString + ")"s);
}

int main() {
  printProgramInfo();
  cg::DefaultAppConfigBuilder<mh::MovingHeadApp> builder{};
  createConfiguration(builder);
  std::unique_ptr<mh::MovingHeadApp> app{
      mh::MovingHeadApp::create(builder.getConfig())};
  return app->runEventLoop();
}
