add_executable(test-strategy strategy.c test-strategy.c ../grid/grid.c)
target_link_libraries(test-strategy m)

add_library(A4_parpaite_seegers_legarrec_fast SHARED A4_parpaite_seegers_legarrec_fast.c)