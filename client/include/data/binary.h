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

#include <string>

#ifdef _MSC_VER
#include <Windows.h>
#endif // _MSC_VER

#include "data/hexdump_cache.h"

namespace machine_decompiler {
namespace client {
namespace data {

class Binary {
  std::string path_;
#ifdef _MSC_VER
  HANDLE bin_file_;
  HANDLE bin_file_mapping_;
#endif // _MSC_VER
  void const* buffer_;
  uint64_t length_;
  HexdumpCache hexdump_cache_;

 public:
  explicit Binary(std::string const& path);
  ~Binary();

  void Load() noexcept(false);

  std::string const& path() const {
    return path_;
  }
  void const* buffer() const {
    return buffer_;
  }
  uint64_t length() const {
    return length_;
  }
  HexdumpCache const& hexdump_cache() const {
    return hexdump_cache_;
  }
};

} // namespace data
} // namespace client
} // namespace machine_decompiler
