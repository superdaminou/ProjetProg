#include "grid.h"

struct grid_s {
	tile t_grid[GRID_SIDE][GRID_SIDE];
	int score;
};


grid new_grid () {
	grid g = malloc(sizeof(struct grid_s));
	assert(g != NULL);

	for(int i = 0 ; i < GRID_SIDE ; i++) {
		for(int j = 0 ; j < GRID_SIDE ; j++) {
			tile t = 0;
			g->t_grid[i][j] = t;
		}
	}
	g->score = 0;
	return g;
}


void delete_grid (grid g) {
	free(g);
}


void copy_grid (grid src, grid dst) {
	for(int i = 0 ; i < GRID_SIDE ; i++) {
		for(int j = 0 ; j < GRID_SIDE ; j++)
			dst->t_grid[i][j] = src->t_grid[i][j];
	}
	dst->score = src->score;
}


unsigned long int grid_score (grid g) {
	return g->score;
}


tile get_tile (grid g, int x, int y) {
	assert((0 <= x && x < GRID_SIDE) && (0 <= y && x < GRID_SIDE));
	return g->t_grid[x][y];
}


void set_tile (grid g, int x, int y, tile t) {
	assert((0 <= x && x < GRID_SIDE) && (0 <= y && x < GRID_SIDE));
	g->t_grid[x][y] = t;
}


// Doc

static bool can_move_facto (grid g, int imin, int imax, int jmin, int jmax, int i1, int j1) {
	for (int i = imin ; i < imax ; i++) {
		for (int j = jmin ; j < jmax ; j++) {
			if((g->t_grid[i][j] == g->t_grid[i+i1][j+j1] || g->t_grid[i+i1][j+j1] == 0) && g->t_grid[i][j] != 0)
				return true;
		}
	}
	return false;
}


bool can_move (grid g, dir d) {
	switch(d) {

	case UP:
		return can_move_facto(g, 0, GRID_SIDE, 1, GRID_SIDE, 0, -1);
		break;

	case DOWN:
		return can_move_facto(g, 0, GRID_SIDE, 0, GRID_SIDE-1, 0, 1);
		break;

	case LEFT:
		return can_move_facto(g, 1, GRID_SIDE, 0, GRID_SIDE, -1, 0);
		break;

	case RIGHT:
		return can_move_facto(g, 0, GRID_SIDE-1, 0, GRID_SIDE, 1, 0);
		break;

	default:
		break;
	}
}
    

bool game_over (grid g) {
	if (can_move (g, UP))
		return false;
	if (can_move (g, DOWN))
		return false;
	if (can_move (g, LEFT))
		return false;
	if (can_move (g, RIGHT))
		return false;
	return true;
}

/* Score you have to reach to win */
#define VICTORY 2048

static void victory (int i) {
	if(pow(2,i) == VICTORY)
		printf("Victoire ! Vous pouvez continuer à jouer.\n\n");
}


// do_move moins complexe : UN SEUL ET UNIQUE PARCOURS DE LA GRILLE !!!!! GG  DOC A FAIRE Facto impossible (la condition change, etc.)

void do_move (grid g, dir d) {
	assert(can_move(g,d));

	switch(d) {

	case UP:
		for (int i = 0 ; i < GRID_SIDE ; i++) {
			int flagMerge = 0;
			int flagMove = (get_tile(g,i,0) == 0)?0:1;
			for (int j = 1 ; j < GRID_SIDE ; j++) {
				int n = get_tile(g, i, j);
				if (n != 0) {
					if (n == get_tile(g, i, flagMerge)) {
						set_tile(g, i, flagMerge, n+1);
						set_tile(g, i, j, 0);
						g->score += pow(2, n+1);
						victory(n+1);
						flagMerge++;
					}
					else {
						set_tile(g, i, flagMove, n);
						if (flagMove != j)
							set_tile(g, i, j, 0);
						flagMerge = flagMove;
						flagMove++;
					}
				}
			}
		}
		break;

	case DOWN:
		for (int i = 0 ; i < GRID_SIDE ; i++) {
			int flagMerge = GRID_SIDE-1;
			int flagMove = (get_tile(g,i,GRID_SIDE-1) == 0)?GRID_SIDE-1:GRID_SIDE-2;
			for (int j = GRID_SIDE-2 ; j >= 0 ; j--) {
				int n = get_tile(g, i, j);
				if (n != 0) {
					if (n == get_tile(g, i, flagMerge)) {
						set_tile(g, i, flagMerge, n+1);
						set_tile(g, i, j, 0);
						g->score += pow(2, n+1);
						victory(n+1);	    
						flagMerge--;
					}
					else {
						set_tile(g, i, flagMove, n);
						if (flagMove != j)
							set_tile(g, i, j, 0);
						flagMerge = flagMove;
						flagMove--;
					}
				}
			}
		}
		break;
  
	case LEFT:
		for (int j = 0 ; j < GRID_SIDE ; j++) {
			int flagMerge = 0;
			int flagMove = (get_tile(g,0,j) == 0)?0:1;
			for (int i = 1 ; i < GRID_SIDE ; i++) {
				int n = get_tile(g, i, j);
				if (n != 0) {
					if (n == get_tile(g, flagMerge, j)) {
						set_tile(g, flagMerge, j, n+1);
						set_tile(g, i, j, 0);
						g->score += pow(2, n+1);
						victory(n+1);
						flagMerge++;
					}
					else {
						set_tile(g, flagMove, j, n);
						if (flagMove != i)
							set_tile(g, i, j, 0);
						flagMerge = flagMove;
						flagMove++;
					}
				}
			}
		}
		break;
  
	case RIGHT:
		for (int j = 0 ; j < GRID_SIDE ; j++) {
			int flagMerge = GRID_SIDE-1;
			int flagMove = (get_tile(g,GRID_SIDE-1,j) == 0)?GRID_SIDE-1:GRID_SIDE-2;
			for (int i = GRID_SIDE-2 ; i >= 0 ; i--) {
				int n = get_tile(g, i, j);
				if (n != 0) {
					if (n == get_tile(g, flagMerge, j)) {
						set_tile(g, flagMerge, j, n+1);
						set_tile(g, i, j, 0);
						g->score += pow(2, n+1);
						victory(n+1);
						flagMerge--;
					}
					else {
						set_tile(g, flagMove, j, n);
						if (flagMove != i)
							set_tile(g, i, j, 0);
						flagMerge = flagMove;
						flagMove--;
					}
				}
			}
		}
		break;
	}
}


// Compte le nombre de cases libres

static int count_empty (grid g) {
	int n = 0;

	for (int i = 0 ; i < GRID_SIDE ; i++) {
		for (int j = 0 ; j < GRID_SIDE ; j++) {
			if (g->t_grid[i][j] == 0)
				n++;
		}
	}
	return n;
}  


/* Cette fonction ajoute aléatoirement une tuile à la grille dans une case vide (avec la probabilité 4 : 1/10 et 2 : 9/10)
 * La méthode consiste à compter le nombre n de cases vides, prendre un nombre aléatoire k entre 0 et n puis placer 
 * la tuile à la k-ème case vide */

        
void add_tile (grid g) {
	int n = count_empty (g);

	if (n == 0)
		return;

	int val = (rand()%10 == 0)?2:1;
	int k = rand()%n;

	for (int i = 0 ; i < GRID_SIDE ; i++) {
		for (int j = 0 ; j < GRID_SIDE ; j++) {
			if (g->t_grid[i][j] == 0) {
				if (k == 0) {
					set_tile(g, i, j, val);
					return;
				}
				k--;
			}
		}
	}
}
                    

void play (grid g, dir d) {
	do_move(g,d);
	add_tile(g);
}
