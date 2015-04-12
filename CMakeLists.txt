cmake_minimum_required(VERSION 2.6)

project(PROJETPROG)
add_definitions(-std=c99)

include_directories(
  ${PROJETPROG_SOURCE_DIR}/grid)

add_subdirectory(grid)
add_subdirectory(test)
add_subdirectory(strategy)
add_library(grid grid/grid.c)

add_executable(play play.c grid/grid.c)
add_executable(playGraph playGraph.c grid/grid.c)
target_link_libraries(play m)
target_link_libraries(playGraph m)

INCLUDE(FindPkgConfig)

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(playGraph ${SDL2_LIBRARIES})

enable_testing()

add_test(test_grid test/test_grid)
