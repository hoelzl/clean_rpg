// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef font_example_font_example_EVENT_DISPATCHER_HPP
#define font_example_font_example_EVENT_DISPATCHER_HPP

#include "app/event_dispatcher.hpp"
#include "font_example_app.hpp"
#include "util/random_number_generator.hpp"

namespace fe {
class FontExampleEventDispatcher
    : public cg::EventDispatcher<fe::FontExampleApp> {
public:
  using cg::EventDispatcher<fe::FontExampleApp>::EventDispatcher;
};
} // namespace fe

#endif // font_example_font_example_EVENT_DISPATCHER_HPP
