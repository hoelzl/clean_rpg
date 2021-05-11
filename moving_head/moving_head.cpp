// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "app/app.hpp"
#include "moving_head_app.hpp"
#include "moving_head_config.hpp"
#include "moving_head_event_dispatcher.hpp"
#include <iostream>

void printProgramInfo() {
  std::cout << "Moving Head example Version "
            << MovingHeadVersion::version_string() << " is up and running!"
            << std::endl;
}

void buildConfiguration(
    cg::DefaultAppConfigBuilder<mh::MovingHeadApp>& builder) {
  builder.setEventDispatcher(std::make_unique<mh::MovingHeadEventDispatcher>())
      .setHeight(800)
      .setWidth(1200)
      .setTitle("Moving Head");
}
int main() {
  printProgramInfo();
  cg::DefaultAppConfigBuilder<mh::MovingHeadApp> builder{};
  buildConfiguration(builder);
  std::unique_ptr<mh::MovingHeadApp> app{
      mh::MovingHeadApp::create(builder.getConfig())};
  return app->runEventLoop();
}
