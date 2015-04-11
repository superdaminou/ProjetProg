#include "strategy.h"
#include "stdlib.h"

void free_strategy(strategy s) {
	free(s->mem);
	free(s->name);
}

void free_memless_strat (strategy strat)
{
  free (strat);
}

// La stratégie random consiste à choisir un mouvement aléatoire à chaque coup

dir A4_parpaite_seegers_legarrec_random(strategy s, grid g) {
  dir t[] = {UP, DOWN, LEFT, RIGHT};
  int i = rand()%4;
  return t[i];  
}

strategy strategy_random() {
	strategy s = malloc(sizeof(struct strategy_s));
	s->name = "A4_parpaite_seegers_legarrec_random";
	s->play_move = A4_parpaite_seegers_legarrec_random;
	s->free_strategy = free_strategy;
}


// La stratégie basique consiste à alterner successivement les mouvements UP, DOWN, LEFT et RIGHT

dir A4_parpaite_seegers_legarrec_basique(strategy s, grid g) {
  dir t[] = {UP, DOWN, LEFT, RIGHT};
  return t[((*(int*)s->mem)++)%4];  
}

strategy strategy_basique() {
	strategy s = malloc(sizeof(struct strategy_s));
	s->mem = malloc(sizeof(int));
	*(int*)(s->mem) = 0;
	s->name = "A4_parpaite_seegers_legarrec_random";
	s->play_move = A4_parpaite_seegers_legarrec_basique;
	s->free_strategy = free_strategy;
}



/* strategy strategy_fast() { */
/* 	strategy s = malloc(sizeof(struct strategy_s)); */
/* 	s->name = "A4_parpaite_seegers_legarrec_fast"; // NE passe probablement pas à la compilation */
/* 	s->play_move = &A4_parpaite_seegers_legarrec_fast; */
/* 	s->free_strategy = free; */
/* } */


/* static int evaluer_grille_fast(grid g) { */
/* 	for (int i = 0 ; i < GRID_SIDE ; i++) { */
/* 		for (int j = 0 , j < GRID_SIDE ; j++) { */
			
	

/* dir A4_parpaite_seegers_legarrec_fast(strategy s, grid g) { */
/* } */

       
