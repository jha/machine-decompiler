# Machine Decompiler

This is a work-in-progress decompiler designed to work using Machine Learning,
rather than algorithmically, allowing users to train the decompiler together
to produce an always-updating product.

## Building from source

```bash
mkdir -p build
cmake -DCMAKE_BUILD_TYPE=Release ../
cmake --build .
```

## Running the client

The default, community integration server credentials are as follows

```
community.hostname.tld
```

## Running the server

_TDB_

## Included Works

This software utilizes [dear imgui](https://github.com/ocornut/imgui), which is
also licensed under the MIT license. As this is the same license this software
is released under, we have not included an additional copy of the MIT license
with the source.
