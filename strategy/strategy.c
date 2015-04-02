#include "strategy.h"
#include "stdlib.h"

strategy strategy_fast() {
	strategy s = malloc(sizeof(struct strategy_s s));
	s->name = "A4_parpaite_seegers_legarrec_fast"; // NE passe probablement pas à la compilation
	s->playmove = &A4_parpaite_seegers_legarrec_fast;
	s->free_strategy = free_fast;
}

void free_fast(strategy s) {
	free(s->mem);
	free(s->name);
}

static int evaluer_grille_fast(grid g) {
	for (int i = 0 ; i < GRID_SIDE ; i++) {
		for (int j = 0 , j < GRID_SIDE ; j++) {
			
	

dir A4_parpaite_seegers_legarrec_fast(strategy s, grid g) {
	
	
	

void free_memless_strat (strategy strat)
{
  free (strat);
}
