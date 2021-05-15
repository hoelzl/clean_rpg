// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_GRIDWORLD_TILE_MAP_HPP
#define CLEAN_RPG_GRIDWORLD_TILE_MAP_HPP

#include "map_data.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <app/resource_manager.hpp>

namespace cr {
class TileMapBase : public sf::Drawable, public sf::Transformable {
public:
  explicit TileMapBase(cg::ResourceManager& resourceManager);

private:
  sf::VertexArray      vertices{};
  cg::ResourceManager& resourceManager;
};

template <std::size_t DimLayers, std::size_t DimW, std::size_t DimH>
class TileMap : public TileMapBase {
public:
  using LayerType     = std::array<std::array<int, DimW>, DimH>;
  using MapType       = std::array<LayerType, DimLayers>;
  using LayerIterator = typename MapType::iterator;

private:
};
} // namespace cr

#endif // CLEAN_RPG_GRIDWORLD_TILE_MAP_HPP
