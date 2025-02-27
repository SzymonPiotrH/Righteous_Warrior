cmake_minimum_required(VERSION 3.30.0)
set (CMAKE_CXX_STANDARD 23)

project(Righteous_Warrior)

set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

set(RAYLIB_VERSION 5.5)
find_package(raylib ${RAYLIB_VERSION} REQUIRED) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_MakeAvailable(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
  endif()
endif()

set(CMAKE_SOURCE_DIR "${MY_ROOT}/src")
list(APPEND sourcesList "src/main.cpp")
add_executable(${PROJECT_NAME} ${sourcesList})

target_link_libraries(${PROJECT_NAME} raylib_LIBRARIES)
