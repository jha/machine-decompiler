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

#ifndef MACHINE_DECOMPILER_UI_ELEMENT_H_
#define MACHINE_DECOMPILER_UI_ELEMENT_H_

#include <string>

#include <imgui.h>

namespace machine_decompiler {
namespace client {
namespace ui {

class Manager;

class Element {
  Manager& manager_;
  std::string id_;
  ImVec2 default_size_;

 protected:
  explicit Element(Manager& manager,
      std::string const& title, ImVec2 const& default_size);

  virtual void Render() = 0;

 public:
  virtual ~Element() = default;

  virtual void Show() = 0;

  Manager& manager() {
    return manager_;
  }
  std::string const& id() const {
    return id_;
  }
  ImVec2 const& default_size() const {
    return default_size_;
  }
};

} // namespace ui
} // namespace client
} // namespace machine_decompiler

#endif // MACHINE_DECOMPILER_UI_ELEMENT_H_
