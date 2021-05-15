// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLEAN_RPG_GRIDWORLD_LAYER_HPP
#define CLEAN_RPG_GRIDWORLD_LAYER_HPP

#include <array>
#include <cstddef>
#include <iterator>
#include <type_traits>

namespace cr {

template <std::size_t DimW, std::size_t DimH>
class [[maybe_unused]] Layer {
  class LayerIterator;

public:
  using DataArray = std::array<std::array<int, DimW>, DimH>;
  using iterator  = LayerIterator;

  static_assert(std::is_nothrow_copy_constructible_v<DataArray>);
  constexpr explicit Layer(const DataArray& data) noexcept : data{data} {}

  [[nodiscard]] int at(unsigned int w, unsigned int h) const {
    return data.at(h).at(w);
  }
  [[nodiscard]] int& at(unsigned int w, unsigned int h) {
    return data.at(h).at(w);
  }

  [[nodiscard]] constexpr std::size_t width() const noexcept { return DimW; }
  [[nodiscard]] constexpr std::size_t height() const noexcept { return DimH; }
  [[nodiscard]] constexpr std::size_t size() const noexcept {
    return DimW * DimH;
  }

  constexpr LayerIterator begin() { return LayerIterator{&data}; }

  constexpr LayerIterator end() { return LayerIterator{&data, 0, DimH}; }

private:
  DataArray data;

  static_assert(std::is_nothrow_copy_constructible_v<LayerIterator>);
  static_assert(std::is_nothrow_copy_constructible_v<DataArray*>);

  // LayerIterator written in the traditional (before C++20) style using tag
  // dispatch.
  class [[maybe_unused]] LayerIterator {
  public:
    using iterator_category [[maybe_unused]] = std::forward_iterator_tag;
    using size_type                          = std::size_t;
    using difference_type [[maybe_unused]]   = std::ptrdiff_t;
    using value_type                         = int;
    using pointer                            = value_type*;
    using const_pointer                      = value_type const*;
    using reference                          = value_type&;
    using const_reference                    = value_type const&;

    // Iterators must be constructable.
    explicit constexpr LayerIterator(DataArray* data, size_type posW = 0,
                                     size_type posH = 0) noexcept
        : data{data}, posW{posW}, posH{posH} {}

    // They must be copy constructable.
    constexpr LayerIterator(const LayerIterator&) noexcept = default;

    // They need not have a move constructor, but they should.
    constexpr LayerIterator(LayerIterator&&) noexcept = default;

    // They must have a copy assignment operator.
    constexpr LayerIterator& operator=(const LayerIterator&) noexcept = default;

    // The don't have to have a move assignment operator, but should.
    constexpr LayerIterator& operator=(LayerIterator&&) noexcept = default;

    // They must have a destructor.
    constexpr ~LayerIterator() noexcept = default;

    // Since we are defining a forward iterator we need to support operators
    // *, ->, ++ (pre- and postfix), == and !=.

    constexpr reference       operator*() { return data->at(posH).at(posW); }
    constexpr const_reference operator*() const {
      return data->at(posH).at(posW);
    }
    constexpr pointer       operator->() { return &*this; }
    constexpr const_pointer operator->() const { return &*this; }

    constexpr LayerIterator& operator++() noexcept {
      if (posW < DimW - 1) {
        ++posW;
      } else {
        posW = 0;
        ++posH;
      }
      return *this;
    }

    const LayerIterator // NOLINT(readability-const-return-type)
    operator++(int) noexcept {
      LayerIterator result{*this};
      ++(*this);
      return result;
    }

    friend constexpr bool operator==(const LayerIterator& lhs,
                                     const LayerIterator& rhs) noexcept {
      return lhs.data == rhs.data && lhs.posW == rhs.posW &&
             lhs.posH == rhs.posH;
    }

    friend constexpr bool operator!=(const LayerIterator& lhs,
                                     const LayerIterator& rhs) noexcept {
      return !(lhs == rhs);
    }

  private:
    DataArray*  data;
    std::size_t posW{0};
    std::size_t posH{0};
  };
};

} // namespace cr

#endif // CLEAN_RPG_GRIDWORLD_LAYER_HPP
