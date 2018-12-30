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

#include "data/binary.h"

#include "error/not_implemented_exception.h"

namespace machine_decompiler {
namespace client {
namespace data {

Binary::Binary(std::string const& path)
    : path_(path) {
}

Binary::~Binary() = default;

#ifdef _MSC_VER
void Binary::Load() {
  throw error::NotImplementedException();
}
#endif // _MSC_VER

#ifdef __unix__
void Binary::Load() {
  throw error::NotImplementedException("Binary::Load()");
}
#endif // __unix__

} // namespace data
} // namespace client
} // namespace machine_decompiler
