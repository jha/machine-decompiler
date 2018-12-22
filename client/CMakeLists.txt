cmake_minimum_required(VERSION 3.12)
project(client)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
    src/main.cc
    src/machine_decompiler.cc)

add_executable(md-client ${SOURCES})
target_include_directories(md-client PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_compile_options(-Wall -Wextra -Werror)