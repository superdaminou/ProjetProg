#include "grid.h"

// Affichage de la grille et du score (version basique à améliorer)

void display_separator() {
  for (int i = 0 ; i < GRID_SIDE ; i++)
    printf("+———————");
  puts("+");
}

void display (grid g) {
  printf("\nScore : %d\n\n", grid_score(g));
  for (int j = 0 ; j < GRID_SIDE ; j++) {
    display_separator();
    for (int i = 0 ; i < GRID_SIDE ; i++) {
      if (get_tile(g,i,j) == 0)
	printf("|%4u   ", get_tile(g,i,j));
      else {
	unsigned int n = (unsigned int) get_tile(g,i,j); // downcast pour affichage
        printf("|%4u   ", (unsigned int) pow(2,n));
      }
    }
    puts("|");
  }
  display_separator();
  printf("\n\n");
}

void auto_play (grid g)
{
  dir t[] = {UP, DOWN, LEFT, RIGHT};
  int i = 0;
  while (!game_over(g))
  {
    i = rand()%4;
    play(g, t[i]);
  }
}

void facto_play (grid g, dir d) {
  play(g, d);
  display(g);
}
  

int main()
{
  srand(time(NULL)); // Initialisation de rand

  grid g = new_grid();
  add_tile(g);
  add_tile(g);
  display(g);

  while (!game_over(g))
  {

    char c;
    dir d;
    scanf("%c", &c);

    switch(c) {
    case 'a':
      auto_play(g);
      display(g);
      break;

    case 'z':
      facto_play(g, UP);
      break;
      
    case 's':
      facto_play(g, DOWN);
      break;

    case 'q':
      facto_play(g, LEFT);
      break;

    case 'd':
      facto_play(g, RIGHT);
      break;
    }
  }

  printf("Score final : %d\n", grid_score(g));
 
  return EXIT_SUCCESS;
}
