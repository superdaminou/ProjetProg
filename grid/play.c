#include "grid.h"

// Affichage de la grille et du score (version basique à améliorer)

void display (grid g) {
  printf("\nScore : %d\n", grid_score(g));
  for (int j = 0 ; j < GRID_SIDE ; j++) {
    printf("\n");
    for (int i = 0 ; i < GRID_SIDE ; i++) {
      if (get_tile(g, i,j) == 0)
	printf(" . ");
      else {
	unsigned int n = (unsigned int) get_tile(g, i,j); // downcast pour affichage
        printf(" %u ", (unsigned int) pow(2,n));
      }
    }
  }
  printf("\n\n");
}

void auto_play (grid g) {
  dir t[] = {UP, DOWN, LEFT, RIGHT};
  int i = 0;
  while (!game_over(g)) {
    i = rand()%4;
    play(g, t[i]);
  }
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
    case 'a':
      auto_play(g);
      display(g);
      break;

    case 'z':
      d = UP;
      play(g, d);
      display(g);
      break;
      
    case 's':
      d = DOWN;
      play(g, d);
      display(g);
      break;

    case 'q':
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

  printf("Score final : %d\n", grid_score(g));
 
  return EXIT_SUCCESS;
}
