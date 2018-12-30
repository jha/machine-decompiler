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

#include <stdio.h>

#include <imgui.h>

#include "ui/window.h"
#include "ui/manager.h"

namespace machine_decompiler {
namespace client {
namespace ui {

namespace {

ImVec2 const winMinSize(128, 64);
ImVec2 const winMaxSize(10000, 10000);

} // namespace

Window::Window(Manager& manager,
    std::string const& title, ImVec2 const& defSize)
    : open_(true),
      new_window_(true),
      Element(manager, title, defSize) {
}

void Window::Show() {
  if (open()) {
    ImGui::SetNextWindowSizeConstraints(winMinSize, winMaxSize);
    if (new_window())
      ImGui::SetNextWindowSize(default_size());
    if (ImGui::Begin(id().c_str(), &open_))
      Render();
    ImGui::End();
  } else {
    manager().Remove(this);
  }
}

} // namespace ui
} // namespace client
} // namespace machine_decompiler
