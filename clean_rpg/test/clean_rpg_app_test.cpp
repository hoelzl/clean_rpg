// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "catch2/catch_all.hpp"
#include "clean_rpg_app.hpp"
#include "clean_rpg_event_dispatcher.hpp"
#include "default_clean_rpg_builder.hpp"
#include <memory>

SCENARIO("a CleanRpgApp can be created using a builder", "[app]") {
  GIVEN("A configuration builder") {
    auto builder{cr::createDefaultBuilder()};
    WHEN("an event dispatcher has been provided") {
      auto eventDispatcher{std::make_unique<cr::CleanRpgEventDispatcher>()};
      builder->setEventDispatcher(std::move(eventDispatcher));
      THEN("the app can be created") {
        std::unique_ptr<cr::CleanRpgApp> app{
            cr::CleanRpgApp::create(builder->getConfig())};
        REQUIRE(app);
      }
    }
  }
}
