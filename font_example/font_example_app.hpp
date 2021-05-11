// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef font_example_font_example_APP_HPP
#define font_example_font_example_APP_HPP

#include "app/app.hpp"

namespace fe {
class FontExampleApp : public cg::App<FontExampleApp> {
public:
  using cg::App<FontExampleApp>::App;
};
} // namespace fe

#endif // font_example_font_example_APP_HPP
