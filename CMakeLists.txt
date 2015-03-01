cmake_minimum_required(VERSION 2.6)

project(PROJETPROG)
add_definitions(-std=c99)

include_directories(
${PROJETPROG_SOURCE_DIR}/grid)

add_subdirectory(grid)
