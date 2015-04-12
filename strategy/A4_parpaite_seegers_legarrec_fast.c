#include "strategy.h"
#include "stdlib.h"

void free_strategy(strategy s) {
	free(s->name);
}

void free_memless_strat(strategy s) {
	free(s);
}

/* La stratégie fast consiste à considérer les plateaux possibles en jouant dans chaque direction possible (4 plateaux au maximum donc), à évaluer un " score " pour ces plateaux, 
   puis à choisir la direction qui donne le plateau ayant le plus grand score.

   ATTENTION : Ce score est à dissocier du score de la grille (i.e. : le score du joueur). cf. doc de la fonction evaluer_score  */

static int count_empty_tiles(grid g) {
	int n = 0;

	for (int i = 0 ; i < GRID_SIDE ; i++) {
		for (int j = 0 ; j < GRID_SIDE ; j++) {
			if (get_tile(g, i, j) == 0)
				n++;
		}
	}
	return n;
}  

static int count_non_monotonicity(grid g) {
	int n = 0;
	int checkMono;
	
	// Parcours des lignes
	for (int j = 0 ; j < GRID_SIDE ; j++) {
		for (int i = 0 ; i < GRID_SIDE-2 ; i++) {
		    checkMono = (get_tile(g, i+1, j) - get_tile(g, i, j)) * (get_tile(g, i+2, j) - get_tile(g, i+1, j));
			if (checkMono < 0)    // Formule simple qui permet de vérifier la monotonie d'une suite de valeurs
				n++;
		}
	}

	// Parcours des colonnes
	for (int i = 0 ; i < GRID_SIDE ; i++) {
		for (int j = 0 ; j < GRID_SIDE-2 ; j++) {
			checkMono = (get_tile(g, i, j+1) - get_tile(g, i, j)) * (get_tile(g, i, j+2) - get_tile(g, i, j+1));
			if (checkMono < 0)
				n++;
		}
	}
	return n;
}

static int search_best_tile(grid g) {
	int best_tile = 0;

	for (int i = 0 ; i < GRID_SIDE ; i++) {
		for (int j = 0 ; j < GRID_SIDE ; j++) {
			if (get_tile(g, i, j) > best_tile)
				best_tile = get_tile(g, i, j);
		}
	}
	return best_tile;
}

static int is_best_tile_in_corner(grid g, int best_tile) {
	return get_tile(g, 0, 0) == best_tile || get_tile(g, GRID_SIDE-1, GRID_SIDE-1) == best_tile || get_tile(g, 0, GRID_SIDE-1) == best_tile || get_tile(g, GRID_SIDE-1, 0) == best_tile;
}

static int is_best_tile_on_edge(grid g, int best_tile) {
	
	for (int i = 0 ; i < GRID_SIDE ; i++) {
		if (get_tile(g, i, 0) == best_tile || get_tile(g, i, GRID_SIDE-1) == best_tile || get_tile(g, 0, i) == best_tile || get_tile(g, GRID_SIDE-1, i) == best_tile)
			return 1;
	}
	return 0;
}
	
	

/* Le score est un nombre qui est d'autant plus grand que la configuration de la grille est favorable pour le joueur.
   Techniquement, le score est obtenu grâce à la fonction evaluer_score qui prend en paramètre un plateau et retourne un nombre entier. 

   Une des difficultés pour avoir une bonne intelligence artificielle est d'avoir une bonne fonction de score. 
   Pour la stratégie fast, nous allons nous contenter d'une fonction très simple : compter les cases vides.
   En cherchant à maximiser le score, nous maximiserons donc les cases vides, et privilégierons donc les directions qui fusionnent le plus de tuiles. */

static int evaluer_score(grid g) {
	int empty_tiles = count_empty_tiles(g);
	int non_monotonicity = count_non_monotonicity(g);
	int best_tile = search_best_tile(g);
	int best_tile_in_corner = is_best_tile_in_corner(g, best_tile);
	int best_tile_on_edge = is_best_tile_on_edge(g, best_tile);

	return (10 * empty_tiles 
			- 2 * non_monotonicity
			+ best_tile
			+ 50 * best_tile_in_corner
			+ 40 * best_tile_on_edge); // L'évaluation du score est d'autant plus élevée qu'il y a de cases vides et peu de non-mononicités
}

dir play_move_fast(strategy s, grid g) {
	dir t[] = {UP, DOWN, LEFT, RIGHT};
	int d;
	int evalMax = -64; // On initialise avec l'evaluation minimale possible
	grid gCopy = new_grid();
	for (int i = 0 ; i < 4 ; i++) {
		if (can_move(g, t[i])) {
			copy_grid(g, gCopy);
			do_move(gCopy, t[i]);
			int evalCurrent = evaluer_score(gCopy);
			if (evalCurrent > evalMax) {
				d = t[i];
				evalMax = evalCurrent;
			}
		}
	}
	delete_grid(gCopy);
	return d;
}

strategy A4_parpaite_seegers_legarrec_fast() {
	strategy s = malloc(sizeof(struct strategy_s));
	s->name = "A4_parpaite_seegers_legarrec_fast";
	s->play_move = play_move_fast;
	s->free_strategy = free_strategy;
} 
