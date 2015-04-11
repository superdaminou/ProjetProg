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
target_link_libraries(play m)

enable_testing()

add_test(test_grid test/test_grid)
