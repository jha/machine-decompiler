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

#ifndef MACHINE_DECOMPILER_ERROR_NOT_IMPLEMENTED_H_
#define MACHINE_DECOMPILER_ERROR_NOT_IMPLEMENTED_H_

#include <string>
#include <stdexcept>

#include <string.h>

namespace machine_decompiler {
namespace client {
namespace error {

class NotImplementedException : public std::logic_error {
  char const* msg_;

 public:
  explicit NotImplementedException(std::string const& member)
      :std::logic_error(member) {
    auto local = (std::string(std::logic_error::what())
        + " is not yet implemented");
    msg_ = new char[local.size() + 1];
    strcpy(const_cast<char*>(msg_), local.c_str());
  }

  ~NotImplementedException() {
    delete msg_;
  }

  char const* what() const override {
    return msg_;
  }
};

} // namespace error
} // namespace client
} // namespace machine_decompiler

#define NotImplementedException() NotImplementedException(__FUNCTION__)

#endif // MACHINE_DECOMPILER_ERROR_NOT_IMPLEMENTED_H_
