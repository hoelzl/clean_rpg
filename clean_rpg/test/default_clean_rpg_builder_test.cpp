// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "catch2/catch_all.hpp"
#include "clean_rpg_app.hpp"
#include "default_clean_rpg_builder.hpp"
#include <memory>

SCENARIO("The default builder contains useful values", "[builder]") {
  GIVEN("the builder returned by the factory function") {
    THEN("It is not empty") { REQUIRE(cr::createDefaultBuilder()); }
    THEN("Its dimensions are correct") {
      REQUIRE(cr::createDefaultBuilder()->getConfig().width == 1200);
      REQUIRE(cr::createDefaultBuilder()->getConfig().height == 800);
    }
    THEN("Its title is correct") {
      REQUIRE(cr::createDefaultBuilder()->getConfig().title.starts_with(
          "Clean RPG"));
    }
  }
}
