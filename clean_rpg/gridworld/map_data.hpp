// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "layer.hpp"
#include <array>
#include <string>

namespace cr::map_data {
constexpr std::size_t numLayers{5};
constexpr std::size_t dimH{20};
constexpr std::size_t dimW{24};

using TextureNameArray = std::array<std::string_view, numLayers>;
using TextureArray     = std::array<Layer<dimW, dimH>, numLayers>;

[[maybe_unused]] extern TextureNameArray textures;
extern TextureArray                      layers;
} // namespace cr::map_data
