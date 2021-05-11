// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef STARTER_KIT_STARTER_KIT_APP_HPP
#define STARTER_KIT_STARTER_KIT_APP_HPP

#include "app/app.hpp"

namespace sk {
class StarterKitApp : public cg::App<StarterKitApp> {
public:
  using cg::App<StarterKitApp>::App;
};
} // namespace sk

#endif // STARTER_KIT_STARTER_KIT_APP_HPP
