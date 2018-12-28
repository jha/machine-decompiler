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

#include "ui/ribbon_window.h"

namespace machine_decompiler {
namespace client {
namespace ui {

RibbonWindow::RibbonWindow()
    : Window("") {
}

void RibbonWindow::Render() {
  // File
  if (ImGui::BeginMenu("File")) {
    if (ImGui::MenuItem("Open", "Ctrl+O")) {

    }
    if (ImGui::MenuItem("Save", "Ctrl+S")) {

    }
    if (ImGui::MenuItem("Close", "Ctrl+W")) {

    }
    ImGui::EndMenu();
  }

  // Settings
  if (ImGui::BeginMenu("Settings")) {
    if (ImGui::MenuItem("UI Fonts")) {

    }
    if (ImGui::MenuItem("Editor Fonts")) {

    }
    ImGui::EndMenu();
  }

  // Help
  if (ImGui::BeginMenu("Help")) {
    if (ImGui::MenuItem("About")) {

    }
    ImGui::EndMenu();
  }
}

void RibbonWindow::Show() {
  if (ImGui::BeginMainMenuBar()) {
    Render();
    ImGui::EndMainMenuBar();
  }
}

} // namespace ui
} // namespace client
} // namespace machine_decompiler
