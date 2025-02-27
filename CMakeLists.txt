cmake_minimum_required(VERSION 3.30.0)
set (CMAKE_CXX_STANDARD 23)

project(Righteous_Warrior)

set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

find_package(raylib REQUIRED)

set(CMAKE_SOURCE_DIR "${MY_ROOT}/src")
list(APPEND sourcesList "src/main.cpp")
add_executable(${PROJECT_NAME} ${sourcesList})

target_link_libraries(${PROJECT_NAME} raylib_LIBRARIES)
