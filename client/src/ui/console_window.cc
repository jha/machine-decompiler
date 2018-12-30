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

#include "ui/console_window.h"
#include "ui/manager.h"
#include "machine_decompiler.h"

namespace machine_decompiler {
namespace client {
namespace ui {

namespace {

ImVec2 const defWinSize(512, 128);
unsigned const maxHistory = 1000;

} // namespace

ConsoleWindow::ConsoleWindow(Manager &manager)
    : Window(manager, "Console", defWinSize) {
}

void ConsoleWindow::Render() {
  static std::string const* history[maxHistory];
  auto len = manager().decompiler().log_output().LatestHistory(
      history, maxHistory);
  static char strbuff[maxHistory * 1024];

  char* curr = strbuff;
  for (auto i = 0u; i < len; ++i)
    curr += sprintf(curr, "%s\n", history[i]->c_str());

  ImVec2 size(ImGui::GetWindowContentRegionWidth(),
      ImGui::GetWindowHeight() - 20);
  ImGui::InputTextMultiline("", strbuff, sizeof (strbuff),
      size, ImGuiInputTextFlags_ReadOnly);
}

void ConsoleWindow::Show() {
  ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.f, 0.f));
  Window::Show();
  ImGui::PopStyleVar(1);
}

} // namespace ui
} // namespace client
} // namespace machine_decompiler
