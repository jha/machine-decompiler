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

#include "ui/open_file_modal.h"
#include "ui/manager.h"

namespace machine_decompiler {
namespace client {
namespace ui {

OpenFileModal::OpenFileModal(Manager &manager)
    : Modal(manager, "Open File") {
}

void OpenFileModal::Render() {
  char buff[1024] = {0};
  ImGui::Text("Paste file path to load. Supports HTTP/S");
  ImGui::PushItemWidth(-0.1f);
  ImGui::InputText("", buff, sizeof (buff));
  ImGui::PopItemWidth();
  if (ImGui::Button("Load")) {
    manager().Remove(this);
  }
}

} // namespace ui
} // namespace client
} // namespace machine_decompiler
