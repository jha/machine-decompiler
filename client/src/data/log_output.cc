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

#include "data/log_output.h"

namespace machine_decompiler {
namespace client {
namespace data {

LogOutput::LogOutput()
    : output_mutex_(),
      output_() {
}

void LogOutput::Log(char const* fmt, ...) {
  char buff[1024 * 16];
  va_list args;
  va_start(args, fmt);
  vsnprintf(buff, sizeof (buff) - 1, fmt, args);
  va_end(args);
  std::lock_guard<std::mutex> lock(output_mutex_);
  output_.push_front(std::string(buff));
}

unsigned LogOutput::LatestHistory(
    std::string const* dstHistory[], unsigned maxlen) {
  if (maxlen == 0)
    return 0;

  auto start_idx = maxlen, written = 0u;
  if (maxlen > output_.size())
    start_idx = output_.size();

  for (auto& line : output_) {
    dstHistory[--start_idx] = &line;
    written++;
    if (start_idx == 0)
      break;
  }

  return written;
}

} // namespace data
} // namespace client
} // namespace machine_decompiler
