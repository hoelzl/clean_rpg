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
  class ConstLayerIterator;

public:
  using DataArray                 = std::array<std::array<int, DimW>, DimH>;
  using iterator [[maybe_unused]] = LayerIterator;
  using const_iterator [[maybe_unused]] = ConstLayerIterator;

  static_assert(std::is_nothrow_copy_constructible_v<DataArray>);
  constexpr explicit Layer(const DataArray& da) noexcept : data{da} {}

  [[nodiscard]] int at(unsigned int w, unsigned int h) const {
    return data.at(h).at(w);
  }
  [[nodiscard]] int& at(unsigned int w, unsigned int h) {
    return data.at(h).at(w);
  }

  [[nodiscard]] constexpr std::size_t width() const noexcept { return DimW; }
  [[nodiscard]] constexpr std::size_t height() const noexcept { return DimH; }
  [[maybe_unused]] [[nodiscard]] constexpr std::size_t size() const noexcept {
    return DimW * DimH;
  }

  LayerIterator                begin() { return LayerIterator{&data}; }
  constexpr ConstLayerIterator begin() const { return LayerIterator{&data}; }
  LayerIterator                end() { return LayerIterator{&data, 0, DimH}; }
  constexpr ConstLayerIterator end() const {
    return LayerIterator{&data, 0, DimH};
  }

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
    using const_pointer [[maybe_unused]]     = const value_type*;
    using reference                          = value_type&;
    using const_reference [[maybe_unused]]   = const value_type&;

    // Iterators must be constructable.
    explicit LayerIterator(DataArray* data, size_type posW = 0,
                           size_type posH = 0) noexcept
        : data{data}, posW{posW}, posH{posH} {}

    // They must be copy constructable.
    LayerIterator(const LayerIterator&) noexcept = default;

    // They need not have a move constructor, but they should.
    LayerIterator(LayerIterator&&) noexcept = default;

    // They must have a copy assignment operator.
    LayerIterator& operator=(const LayerIterator&) noexcept = default;

    // The don't have to have a move assignment operator, but should.
    LayerIterator& operator=(LayerIterator&&) noexcept = default;

    // They must have a destructor.
    ~LayerIterator() noexcept = default;

    // Since we are defining a forward iterator we need to support operators
    // *, ->, ++ (pre- and postfix), == and !=.

    reference operator*() const { return data->at(posH).at(posW); }
    pointer   operator->() const { return &*this; }

    LayerIterator& operator++() noexcept {
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

    friend bool operator==(const LayerIterator& lhs,
                           const LayerIterator& rhs) noexcept {
      return lhs.data == rhs.data && lhs.posW == rhs.posW &&
             lhs.posH == rhs.posH;
    }

    friend bool operator!=(const LayerIterator& lhs,
                           const LayerIterator& rhs) noexcept {
      return !(lhs == rhs);
    }

  private:
    DataArray*  data;
    std::size_t posW{0};
    std::size_t posH{0};
  };

  static_assert(std::is_nothrow_copy_constructible_v<ConstLayerIterator>);
  static_assert(std::is_nothrow_copy_constructible_v<const DataArray*>);

  class [[maybe_unused]] ConstLayerIterator {
  public:
    using iterator_category [[maybe_unused]] = std::forward_iterator_tag;
    using size_type                          = std::size_t;
    using difference_type [[maybe_unused]]   = std::ptrdiff_t;
    using value_type                         = int;
    using pointer [[maybe_unused]]           = value_type*;
    using const_pointer                      = const value_type*;
    using reference [[maybe_unused]]         = value_type&;
    using const_reference                    = const value_type&;

    // Iterators must be constructable.
    explicit constexpr ConstLayerIterator(const DataArray* data,
                                          size_type        posW = 0,
                                          size_type        posH = 0) noexcept
        : data{data}, posW{posW}, posH{posH} {}

    // They must be copy constructable.
    constexpr ConstLayerIterator(const ConstLayerIterator&) noexcept = default;

    // They need not have a move constructor, but they should.
    constexpr ConstLayerIterator(ConstLayerIterator&&) noexcept = default;

    // They must have a copy assignment operator.
    constexpr ConstLayerIterator&
    operator=(const ConstLayerIterator&) noexcept = default;

    // The don't have to have a move assignment operator, but should.
    constexpr ConstLayerIterator&
    operator=(ConstLayerIterator&&) noexcept = default;

    // They must have a destructor.
    constexpr ~ConstLayerIterator() noexcept = default;

    // Since we are defining a forward iterator we need to support operators
    // *, ->, ++ (pre- and postfix), == and !=.

    constexpr const_reference operator*() const {
      return data->at(posH).at(posW);
    }
    constexpr const_pointer operator->() { return &*this; }
    constexpr const_pointer operator->() const { return &*this; }

    constexpr ConstLayerIterator& operator++() noexcept {
      if (posW < DimW - 1) {
        ++posW;
      } else {
        posW = 0;
        ++posH;
      }
      return *this;
    }

    const ConstLayerIterator // NOLINT(readability-const-return-type)
    operator++(int) noexcept {
      ConstLayerIterator result{*this};
      ++(*this);
      return result;
    }

    friend constexpr bool operator==(const ConstLayerIterator& lhs,
                                     const ConstLayerIterator& rhs) noexcept {
      return lhs.data == rhs.data && lhs.posW == rhs.posW &&
             lhs.posH == rhs.posH;
    }

    friend constexpr bool operator!=(const ConstLayerIterator& lhs,
                                     const ConstLayerIterator& rhs) noexcept {
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
