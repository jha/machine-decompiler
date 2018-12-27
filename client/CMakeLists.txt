cmake_minimum_required(VERSION 3.12)
project(client)

add_definitions(-DCMAKE_GENERATOR_PLATFORM=x64)
add_subdirectory(ultralight)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
    src/main.cc
    src/machine_decompiler.cc
    )

if (MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /GR-")
elseif(UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
endif()

add_executable(md-client ${SOURCES})
message(${CMAKE_CURRENT_SOURCE_DIR})
find_library(ULTRALIGHT_LIB
    NAMES Ultralight
    PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ultralight/lib/win/x64"
    PATH_SUFFIXES lib
    NO_DEFAULT_PATH
    )
find_library(ULTRALIGHT_CORE_LIB
    NAMES UltralightCore
    PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ultralight/lib/win/x64"
    PATH_SUFFIXES lib
    NO_DEFAULT_PATH
    )
find_library(ULTRALIGHT_WEB_LIB
    NAMES WebCore
    PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ultralight/lib/win/x64"
    PATH_SUFFIXES lib
    NO_DEFAULT_PATH
    )
target_link_libraries(md-client ${ULTRALIGHT_LIB} ${ULTRALIGHT_CORE_LIB} ${ULTRALIGHT_WEB_LIB})
target_include_directories(md-client PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/ultralight/include
    )

add_compile_options(-Wall -Wextra -Werror)