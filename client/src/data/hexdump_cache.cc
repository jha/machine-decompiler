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
#include <assert.h>

#include "data/hexdump_cache.h"
#include "data/binary.h"

namespace machine_decompiler {
namespace client {
namespace data {

namespace {
unsigned const kMaxLineLen = ((16 * 3) + 2 + (16 * 2) + 1);
} // namespace

HexdumpCache::HexdumpCache(Binary& binary)
    : binary_(binary),
      hex_buff_(nullptr) {
}

HexdumpCache::~HexdumpCache() {
  delete hex_buff_;
}

void HexdumpCache::Load() {
  delete hex_buff_;
  auto* buff = new char[((binary().length() / 16) + 1) * kMaxLineLen];
  auto const* p = reinterpret_cast<uint8_t const*>(binary().buffer());
  hex_buff_ = buff;
  uint64_t i;

  // Process 16 bytes at a time
  auto aligned_len = binary().length() - (binary().length() % 16);
  for (i = 0ll; i < aligned_len; i += 16, p += 16) {
    buff += sprintf(buff,
        "%02X %02X %02X %02X %02X %02X %02X %02X "
        "%02X %02X %02X %02X %02X %02X %02X %02X  "
        "%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",
        p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7],
        p[8], p[9], p[10], p[11], p[12], p[13], p[14], p[15],
        p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7],
        p[8], p[9], p[10], p[11], p[12], p[13], p[14], p[15]);
  }

  // Process 1 byte at a time. This algorithm is borrowed from Stack Overflow
  char leftover[17];
  for (i = aligned_len; i < binary().length(); ++i, ++p) {
    if ((i % 16) == 0) {
      if (i != 0)
        buff += sprintf(buff, "  %s\n", leftover);
    }

    buff += sprintf(buff, " %02X", *p);

    if (*p < 0x20 || (*p > 0x7e))
      leftover[i % 16] = '.';
    else
      leftover[i % 16] = *p;
    leftover[(i % 16) + 1] = '\0';
  }

  while ((i % 16) != 0) {
    buff += sprintf(buff, "   ");
    ++i;
  }

  // Print out final ASCII bit
  sprintf(buff, "  %s\n", leftover);

  hex_buff_length_ = static_cast<uint64_t>(buff - hex_buff_);
}

} // namespace data
} // namespace client
} // namespace machine_decompiler
