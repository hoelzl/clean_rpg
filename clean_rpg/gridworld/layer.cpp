// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include "layer.hpp"

namespace cr {
Layer<3, 2>                layer{{{{1, 2, 3}, {4, 5, 6}}}};
std::array<Layer<4, 3>, 2> arr_lay{
    Layer<4, 3>{{{{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}}}},
    Layer<4, 3>{{{{4, 2, 3, 4}, {5, 2, 3, 4}, {6, 2, 3, 4}}}}};
} // namespace cr
