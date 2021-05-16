// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "app/app.hpp"
#include "clean_rpg_app.hpp"
#include "clean_rpg_config.hpp"
#include "default_clean_rpg_builder.hpp"
#include <iostream>

using namespace std::string_literals;

void printProgramInfo() {
  std::cout << "Clean RPG Version " << CleanRpgVersion::version_string()
            << " is up and running!" << std::endl;
}

cr::Layer<2, 3> myLayer{{{{1, 2}, {3, 4}, {5, 6}}}};
std::size_t computeLayerSum() {
  size_t sum{0L};
  for (int idx : myLayer) {
    sum += idx;
  }
  return sum;
}

void printArrayInfo() {
  auto numLayers{cr::map_data::numLayers};
  auto height{cr::map_data::layers[numLayers - 1].height()};
  auto width{cr::map_data::layers[numLayers - 1].width()};
  std::cout << "numLayers = " << numLayers << ", height = " << height
            << ", width = " << width << std::endl;
  std::cout << "Element: "
            << cr::map_data::layers.at(numLayers - 1).at(width - 1, height - 1)
            << std::endl;
  size_t sum{computeLayerSum()};
  std::cout << "Sum: " << sum << std::endl;
}

#ifdef USE_CONCEPTS
void printUseConcepts() { std::cout << "We ARE using concepts." << std::endl; }
#else
void printUseConcepts() {
  std::cout << "We are NOT using concepts." << std::endl;
}
#endif

int main() {
  printProgramInfo();
  printArrayInfo();
  printUseConcepts();
  auto builder{cr::createDefaultBuilder()};
  std::unique_ptr<cr::CleanRpgApp> app{
      cr::CleanRpgApp::create(builder->getConfig())};
  return app->runEventLoop();
}
