cmake_minimum_required(VERSION 3.12)
project(client)

set(CMAKE_CXX_STANDARD 14)

# The main application sources

set(SOURCES
    src/main.cc
    src/machine_decompiler.cc
    src/data/binary.cc
    src/ui/manager.cc
    src/ui/element.cc
    src/ui/window.cc
    src/ui/ribbon_window.cc
    src/ui/functions_window.cc
    src/ui/strings_window.cc
    src/ui/disasm_window.cc
    src/ui/hexdump_window.cc
    src/ui/console_window.cc
    )

# Generic dear imgui sources required for bindings-independent GUIs

add_library(imgui STATIC
    imgui/imgui.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_widgets.cpp
    )

# We want to use as generic bindings as possifle for imgui so we don't have
# to write any platform-specific code

add_library(imgui-bindings STATIC
    imgui/examples/imgui_impl_glfw.cpp
    imgui/examples/imgui_impl_opengl3.cpp
    imgui/examples/libs/gl3w/GL/gl3w.c)
target_include_directories(imgui-bindings PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/examples
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/examples/libs/glfw/include
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/examples/libs/gl3w
    )
find_library(GLFW3_LIB
    NAMES glfw3_2018
    PATHS "${CMAKE_CURRENT_SOURCE_DIR}"
    PATH_SUFFIXES lib
    NO_DEFAULT_PATH
    )
find_library(OPENGL_LIB
    NAMES Opengl32
    PATH_SUFFIXES lib
    )
target_link_libraries(imgui-bindings ${OPENGL_LIB} ${GLFW3_LIB})

add_executable(md-client ${SOURCES})
target_link_libraries(md-client
    imgui
    imgui-bindings
    )

target_include_directories(md-client PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/examples
    )

add_compile_options(-Wall -Wextra -Werror)