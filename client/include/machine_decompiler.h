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

#ifndef MACHINE_DECOMPILER_H_
#define MACHINE_DECOMPILER_H_

#include <string>

#include "data/log_output.h"
#include "data/binary.h"
#include "ui/manager.h"

namespace machine_decompiler {
namespace client {

class MachineDecompiler {
  data::LogOutput log_output_;
  data::Binary* binary_;
  ui::Manager ui_manager_;

 public:
  MachineDecompiler();
  void ShowWindow();
  void LoadBinary(std::string& path) noexcept(false);

  ui::Manager& ui_manager() {
    return ui_manager_;
  }
  data::LogOutput& log_output() {
    return log_output_;
  }
  data::Binary* binary() {
    return binary_;
  }
};

} // namespace client
} // namespace machine_decompiler

#endif // MACHINE_DECOMPILER_H_
