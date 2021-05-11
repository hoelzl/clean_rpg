// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "app/app.hpp"
#include "font_example_app.hpp"
#include "font_example_config.hpp"
#include "font_example_event_dispatcher.hpp"
#include <iostream>

using namespace std::literals::string_literals;

void printProgramInfo() {
  std::cout << "Font example Version " << FontExampleVersion::version_string()
            << " is up and running!" << std::endl;
}

void buildConfiguration(
    cg::DefaultAppConfigBuilder<fe::FontExampleApp>& builder) {
  auto eventDispatcher{std::make_unique<fe::FontExampleEventDispatcher>()};
  builder.setEventDispatcher(std::move(eventDispatcher))
      .setHeight(800)
      .setWidth(1200)
      .setTitle("Font Example (Version "s +
                FontExampleVersion::version_string() + ")");
}
int main() {
  printProgramInfo();
  cg::DefaultAppConfigBuilder<fe::FontExampleApp> builder{};
  buildConfiguration(builder);
  std::unique_ptr<fe::FontExampleApp> app{
      fe::FontExampleApp::create(builder.getConfig())};
  return app->runEventLoop();
}
