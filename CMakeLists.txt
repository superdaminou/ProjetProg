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
target_link_libraries(playGraph m ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} SDL2 SDL2_image SDL2_ttf)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2_REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2_image_REQUIRED sdl2_image)
PKG_SEARCH_MODULE(SDL2_ttf_REQUIRED SDL2_ttf)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} 
${SDL2_IMAGE_INCLUDE_DIR} 
${SDL2_TTF_INCLUDE_DIR})
enable_testing()

add_test(test_grid test/test_grid)
