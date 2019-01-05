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

#include <imgui.h>

#include "ui/hexdump_window.h"
#include "ui/manager.h"
#include "machine_decompiler.h"

namespace machine_decompiler {
namespace client {
namespace ui {

namespace {

ImVec2 const defWinSize(256, 384);

} // namespace

HexdumpWindow::HexdumpWindow(Manager &manager)
    : Window(manager, "Hexdump", defWinSize) {
}

void HexdumpWindow::Render() {
  auto& hdc = manager().decompiler().binary()->hexdump_cache();

  ImVec2 size(ImGui::GetWindowContentRegionWidth(),
      ImGui::GetWindowHeight() - 20);
  ImGui::InputTextMultiline("", const_cast<char*>(hdc.hex_buff()),
      hdc.hex_buff_length(), size, ImGuiInputTextFlags_ReadOnly);
}

void HexdumpWindow::Show() {
  ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.f, 0.f));
  auto const& winbg = ImGui::GetStyle().Colors[ImGuiCol_WindowBg];
  ImGui::PushStyleColor(ImGuiCol_FrameBg, winbg);
  Window::Show();
  ImGui::PopStyleColor(1);
  ImGui::PopStyleVar(1);
}

} // namespace ui
} // namespace client
} // namespace machine_decompiler
