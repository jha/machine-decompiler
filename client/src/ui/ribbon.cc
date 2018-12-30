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

#include "ui/ribbon.h"
#include "ui/manager.h"
#include "ui/functions_window.h"
#include "ui/strings_window.h"
#include "ui/disasm_window.h"
#include "ui/hexdump_window.h"
#include "ui/console_window.h"
#include "ui/open_file_modal.h"
#include "ui/about_modal.h"

namespace machine_decompiler {
namespace client {
namespace ui {

Ribbon::Ribbon(Manager& manager)
    : Element(manager, "", ImVec2(0, 0)) {
}

void Ribbon::Render() {
  // File
  if (ImGui::BeginMenu("File")) {
    if (ImGui::MenuItem("Open", "Ctrl+O")) {
      manager().Add(new OpenFileModal(manager()));
    }
    if (ImGui::MenuItem("Save", "Ctrl+S")) {

    }
    ImGui::EndMenu();
  }

  // View
  if (ImGui::BeginMenu("View")) {
    if (ImGui::MenuItem("Functions", "Ctrl+N")) {
      manager().Add(new FunctionsWindow(manager()));
    }
    if (ImGui::MenuItem("Strings", "Ctrl+T")) {
      manager().Add(new StringsWindow(manager()));
    }
    if (ImGui::MenuItem("Disassembly", "Ctrl+D")) {
      manager().Add(new DisasmWindow(manager()));
    }
    if (ImGui::MenuItem("Hexdump", "Ctrl+H")) {
      manager().Add(new HexdumpWindow(manager()));
    }
    if (ImGui::MenuItem("Console", "Ctrl+K")) {
      manager().Add(new ConsoleWindow(manager()));
    }
    ImGui::EndMenu();
  }

  // Settings
  if (ImGui::BeginMenu("Settings")) {
    if (ImGui::MenuItem("Fonts")) {

    }
    if (ImGui::MenuItem("Proxy")) {

    }
    ImGui::EndMenu();
  }

  // Help
  if (ImGui::BeginMenu("Help")) {
    if (ImGui::MenuItem("About")) {
      manager().Add(new AboutModal(manager()));
    }
    ImGui::EndMenu();
  }
}

void Ribbon::Show() {
  if (ImGui::BeginMainMenuBar()) {
    Render();
    ImGui::EndMainMenuBar();
  }
}

} // namespace ui
} // namespace client
} // namespace machine_decompiler
