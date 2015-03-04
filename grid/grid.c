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
    // free(g->grid); inutile dans le cadre d'un tableau statique
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
    g->t_grid[x][y] = t;
}


bool can_move (grid g, dir d) {
  switch(d) {
    
  case UP:
    for(int i = 0 ; i < GRID_SIDE ; i++) {
	for(int j = 1 ; j < GRID_SIDE ; j++) {
	    if(g->t_grid[i][j] == g->t_grid[i][j-1] || g->t_grid[i][j-1] == 0)
	      return true;
	}
    }
    break;

  case DOWN:
    for(int i = 0 ; i < GRID_SIDE ; i++) {
	for(int j = 0 ; j < GRID_SIDE-1 ; j++){
	  if(g->t_grid[i][j] == g->t_grid[i][j+1] || g->t_grid[i][j+1] == 0)
	    return true;
	}
    }
    break;
    
  case LEFT:
    for(int i = 1 ; i < GRID_SIDE ; i++) {
	for(int j = 0 ; j < GRID_SIDE ; j++) {
	  if(g->t_grid[i][j] == g->t_grid[i-1][j] || g->t_grid[i-1][j] == 0)
	    return true;
	}
    }
    break;
    
  case RIGHT:
    for(int i = 0 ; i < GRID_SIDE-1 ; i++) {
	for(int j = 0 ; j < GRID_SIDE ; j++){
	  if(g->t_grid[i][j] == g->t_grid[i+1][j] || g->t_grid[i+1][j] == 0)
	    return true;
	}
    }
    break;
  }
    
  return false;
}


bool game_over (grid g) {
    if (can_move (g, UP))
        return  false;
    if (can_move (g, DOWN))
        return false;
    if (can_move (g, LEFT))
        return false;
    if (can_move (g, RIGHT))
        return false;
    return true;
}


// Réécrire do_move : ne marche pas dans la plupart des cas
    
void do_move (grid g, dir d) {
  assert(can_move(g,d));

  switch(d) {
  case UP:
    for (int i = 0 ; i < GRID_SIDE ; i++) {
	for (int j = 0 ; j < GRID_SIDE ; j++) {
	  if (g->t_grid[i][j] != 0) {
	    if(g->t_grid[i][j-1] == 0) {
	      g->t_grid[i][j-1] = g->t_grid[i][j];
	      g->t_grid[i][j] = 0;
	    }
	    if (g->t_grid[i][j] == g->t_grid[i][j-1]) {
	      g->t_grid[i][j-1] += g->t_grid[i][j];
	      g->t_grid[i][j] = 0;
	    }
	  }
	}
    }
    break;
                
  case LEFT:
    for (int i = 1 ; i < GRID_SIDE ; i++) {
      for (int j = 0 ; j < GRID_SIDE ; j++) {
	if (g->t_grid[i][j] != 0) {
	  if(g->t_grid[i-1][j] == 0) {
	    g->t_grid[i-1][j] = g->t_grid[i][j];
	    g->t_grid[i][j] = 0;
	  }
	  if (g->t_grid[i-1][j] == g->t_grid[i][j]) {
	    g->t_grid[i-1][j] += g->t_grid[i][j];
	    g->t_grid[i][j] = 0;
	  }
	}
      } 
    }
    break;
                
  case DOWN:
    for (int i = 0 ; i < GRID_SIDE ; i++)
      {
	for (int j = 0 ; j < GRID_SIDE-1 ; j++)
	  {
	    if (g->t_grid[i][j] != 0)
	      {
		if (g->t_grid[i][j+1] == 0)
		  {
		    g->t_grid[i][j+1] = g->t_grid[i][j];
		    g->t_grid[i][j] = 0;
		  }
		if (g->t_grid[i][j] == g->t_grid[i][j+1])
		  {
		    g->t_grid[i][j+1] += g->t_grid[i][j];
		    g->t_grid[i][j] = 0;
		  }
	      }
	  }
      }
    break;
                
  case RIGHT:
    for (int i = 1 ; i < GRID_SIDE-1 ; i++)
      {
	for (int j = 0 ; j < GRID_SIDE ; j++)
	  {
	    if (g->t_grid[i][j] != 0)
	      {
		if (g->t_grid[i+1][j] == 0)
		  {
		    g->t_grid[i+1][j] = g->t_grid[i][j];
		    g->t_grid[i][j] = 0;
		  }
		if (g->t_grid[i][j] == g->t_grid[i+1][j])
		  {
		    g->t_grid[i][j+1] += g->t_grid[i][j];
		    g->t_grid[i][j] = 0;
		  }
	      }
	  }
      }
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
  if(can_move (g,d)) {
    do_move (g,d); 
    add_tile(g);
  }
}


// Affichage de la grille et du score (version basique à améliorer)

void display (grid g) {
  printf("\nScore : %d\n", g->score);
  for (int i = 0 ; i < GRID_SIDE ; i++) {
    printf("\n");
    for (int j = 0 ; j < GRID_SIDE ; j++) {
      if (g->t_grid[i][j] == 0)
	printf(" . ");
      else {
	unsigned int n = (unsigned int) g->t_grid[i][j];
        printf(" %u ", (unsigned int) pow(2,n));
      }
    }
  }
  printf("\n\n");
}


int main() {
  srand(time(NULL)); // Initialisation de rand

  grid g = new_grid();
  add_tile(g);
  add_tile(g);
  display(g);

  while (!game_over(g)) {

    char c;
    dir d;
    scanf("%c", &c);

    switch(c) {
    case 'h':
      d = UP;
      play(g, d);
      display(g);
      break;
      
    case 'b':
      d = DOWN;
      play(g, d);
      display(g);
      break;

    case 'g':
      d = LEFT;
      play(g, d);
      display(g);
      break;

    case 'd':
      d = RIGHT;
      play(g, d);
      display(g);
      break;
    }
  }

  printf("Score final : %d\n", g->score);
 
  return EXIT_SUCCESS;
}
