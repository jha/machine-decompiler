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

#include <stdexcept>

#ifdef _MSC_VER

#endif // _MSC_VER
#ifdef __unix__
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#endif // __unix__

#include "data/binary.h"
#include "error/not_implemented_exception.h"

namespace machine_decompiler {
namespace client {
namespace data {

Binary::Binary(std::string const& path)
    : path_(path),
#ifdef _MSC_VER
      bin_file_(nullptr),
      bin_file_mapping_(nullptr),
#endif // _MSC_VER
      buffer_(nullptr),
      length_(0ll),
      hexdump_cache_(*this) {
}

#ifdef _MSC_VER
Binary::~Binary() {
  if (bin_file_mapping_ != nullptr)
    CloseHandle(bin_file_);
  if (bin_file_ != nullptr)
    CloseHandle(bin_file_);
}
#endif // _MSC_VER

#ifdef __unix__
Binary::~Binary() = default;
#endif // __unix__

#ifdef _MSC_VER
void Binary::Load() {
  // Open a Windows HANDLE to an existing file
  bin_file_ = CreateFileA(
      path_.c_str(),
      GENERIC_READ | GENERIC_WRITE,
      0,
      nullptr, // TODO: Can't be inherited by child processes!
      OPEN_EXISTING,
      FILE_ATTRIBUTE_NORMAL,
      nullptr);
  if (bin_file_ == nullptr)
    throw std::exception(("Unable to open file " + path()).c_str());

  LARGE_INTEGER fileSize;
  if (!GetFileSizeEx(bin_file_, &fileSize))
    throw std::exception(("Unable to get file size for " + path()).c_str());

  bin_file_mapping_ = CreateFileMappingA(
      bin_file_,
      nullptr,
      PAGE_READWRITE,
      0, 0,
      nullptr);
  if (bin_file_mapping_ == nullptr) {
    throw std::exception(
        ("Unable to map file " + path() + " into memory").c_str());
  }

  auto const* mem = MapViewOfFile(
      bin_file_mapping_,
      FILE_MAP_ALL_ACCESS,
      0, 0,
      0);
  if (mem == nullptr)
    throw std::exception(("Unable to map view of file " + path()).c_str());

  buffer_ = mem;
  length_ = static_cast<uint64_t>(fileSize.QuadPart);

  hexdump_cache_.Load();
}
#endif // _MSC_VER

#ifdef __unix__
void Binary::Load() {
  // Try to open the file
  auto fd = open(path.c_str(), O_RDWR);
  if (fd == -1)
    throw std::exception("Unable to open file " + path);

  // Get the size of the file

  // Map the file into memory
  auto const* bin_disk = mmap(nullptr, 0ll, PROT_READ, MAP_PRIVATE, fd, 0);
  if (bin_disk == MAP_FAILED) {
    close(fd);
    throw std::exception("Unable to map " + path + " into memory");
  }
  hexdump_cache_.Load();
}
#endif // __unix__

} // namespace data
} // namespace client
} // namespace machine_decompiler
