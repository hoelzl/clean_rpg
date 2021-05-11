// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef STARTER_KIT_STARTER_KIT_EVENT_DISPATCHER_HPP
#define STARTER_KIT_STARTER_KIT_EVENT_DISPATCHER_HPP

#include "app/event_dispatcher.hpp"
#include "starter_kit_app.hpp"
#include "util/random_number_generator.hpp"

namespace sk {
class StarterKitEventDispatcher
    : public cg::EventDispatcher<sk::StarterKitApp> {
public:
  using cg::EventDispatcher<sk::StarterKitApp>::EventDispatcher;
};
} // namespace sk

#endif // STARTER_KIT_STARTER_KIT_EVENT_DISPATCHER_HPP
