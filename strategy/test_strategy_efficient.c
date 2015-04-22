#include "strategy.h"
#include "stdlib.h"
#include "math.h"

strategy A4_parpaite_seegers_legarrec_efficient();
void free_strategy(strategy);

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
  printf("[Début du test efficient]\n");
  grid g = new_grid();
  add_tile(g);
  add_tile(g);
  display(g);
  strategy s = A4_parpaite_seegers_legarrec_efficient();
  while(!game_over(g)) {
	  dir d = s->play_move(s, g);
	  if (can_move(g, d)) {
		  play(g, d);
		  printf("Score : %d\n", grid_score(g));
	  }
  }
  display(g);
  free_strategy(s);
  free_memless_strat(s);
  delete_grid(g);
  
  printf("[Fin du test efficient]\n");
}
