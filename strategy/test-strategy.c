#include "strategy.h"
#include "stdlib.h"
#include "math.h"

void display_separator() {
	for (int i = 0 ; i < GRID_SIDE ; i++)
		printf("+———————");
	puts("+");
}

void display (grid g) {
	printf("\nScore : %lu\n\n", grid_score(g));
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

int main() {
  printf("[Début du test random]\n");

  srand(time(NULL)); // Initialisation de random
  grid g1 = new_grid();
  add_tile(g1);
  add_tile(g1);
  display(g1);
  strategy s1 = strategy_random();

  while(!game_over(g1)) {
    dir d = s1->play_move(s1, g1);
    if (can_move(g1, d)) {
      play(g1, d);
    }
  }
  display(g1);
  delete_grid(g1);

  printf("[Fin du test random]\n\n");

  printf("[Début du test basique]\n");

  grid g2 = new_grid();
  add_tile(g2);
  add_tile(g2);
  display(g2);
  strategy s2 = strategy_basique();

   while(!game_over(g2)) {
    dir d = s2->play_move(s2, g2);
    if (can_move(g2, d)) {
      play(g2, d);
    }
  }
  display(g2);
  delete_grid(g2);
  
  printf("[Fin du test basique]\n");
}
