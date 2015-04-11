add_executable(test-strategy strategy.c test-strategy.c ../grid/grid.c)
target_link_libraries(test-strategy m)