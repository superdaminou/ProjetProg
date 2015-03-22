cmake_minimum_required(VERSION 2.6)

project(PROJETPROG)
add_definitions(-std=c99)

include_directories(
  ${PROJETPROG_SOURCE_DIR}/grid)

add_subdirectory(grid)
add_library(grid grid/grid.c)

add_executable(play play.c grid/grid.c)
target_link_libraries(play m)
