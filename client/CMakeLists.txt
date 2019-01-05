cmake_minimum_required(VERSION 3.12)
project(client)

set(CMAKE_CXX_STANDARD 14)

# The main application sources

set(SOURCES
    src/main.cc
    src/machine_decompiler.cc
    src/data/binary.cc
    src/data/log_output.cc
    src/data/hexdump_cache.cc
    src/ui/manager.cc
    src/ui/element.cc
    src/ui/window.cc
    src/ui/modal.cc
    src/ui/ribbon.cc
    src/ui/functions_window.cc
    src/ui/strings_window.cc
    src/ui/disasm_window.cc
    src/ui/hexdump_window.cc
    src/ui/console_window.cc
    src/ui/flow_graph_window.cc
    src/ui/open_file_modal.cc
    src/ui/about_modal.cc
    )

# Get the current branch we're building
find_package(Git)
if (GIT_FOUND)
  message("Found git ${GIT_EXECUTABLE}")
endif(GIT_FOUND)
message(${CMAKE_CURRENT_SOURCE_DIR})
execute_process(
    COMMAND "\"${GIT_EXECUTABLE}\" rev-parse --abbrev-ref HEAD -- | head -n1"
    RESULT_VARIABLE RESULT
    OUTPUT_VARIABLE MD_BRANCH
    )
if (RESULT EQUAL 0)
  message("Detected branch ${MD_BRANCH}")
else()
  set(MD_BRANCH "UNKNOWN")
  message("Unable to detect git branch: ${RESULT}")
  message("Not in git repository, set branch to ${MD_BRANCH}")
endif()
add_definitions("-DBRANCH=\"${MD_BRANCH}\"")

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