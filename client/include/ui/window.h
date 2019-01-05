/*
 * Copyright 2018 github.com/jha
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef MACHINE_DECOMPILER_UI_WINDOW_H_
#define MACHINE_DECOMPILER_UI_WINDOW_H_

#include <string>

#include <imgui.h>

#include "ui/element.h"

namespace machine_decompiler {
namespace client {
namespace ui {

namespace {

ImVec2 const newWindowDefaultSize(128, 256);

} // namespace

class Manager;

class Window : public Element {
  bool open_;
  bool new_window_;

 protected:
  explicit Window(Manager& manager,
      std::string const& title, ImVec2 const& defSize = newWindowDefaultSize);

 public:
  void Show() override;

  bool open() const {
    return open_;
  }

 private:
  bool new_window() {
    if (new_window_) {
      new_window_ = false;
      return true;
    }
    return false;
  }
};

} // namespace ui
} // namespace client
} // namespace machine_decompiler

#endif // MACHINE_DECOMPILER_UI_WINDOW_H_
