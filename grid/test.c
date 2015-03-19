#include "grid.h"

//test des fonctions

void main(grid g){
  grid g=new_grid();
  test_creation_grille(g);
  test_copie(g);
  test_add_tile();
  


}

void test_creation_grille(grid g){
  if(g->score==0)
    printf("score initialisé à 0");
  for(int i=0;i<GRID_SIDE;i++){
    for(int j=0;j<GRID_SIDE;j++){
      if(g->t_grid[i][j]!=0){
		printf("erreur d'initialisation de la grille");
		break;
      }
      printf("verification de l'initialisation des cases de la grille à 0");
    }
  }
}

   
void test_copie(grid g){
  grid g1=new_grid();
  copy_grid(g,g1);
  for(int i = 0 ; i < GRID_SIDE ; i++) {
    for(int j = 0 ; j < GRID_SIDE ; j++){
      if(g->t_grid[i][j] != g1->t_grid[i][j]){
	printf("erreur de copie");
	break;
      }
    }
  }
  if(g->score==g1->score)
    printf("verification de la copie de 2 grid");
  printf("erreur de la copie du score");
}

void test_add_tile(grid g)
	int i=count_empty(g);
	add_tile(g);
	if((count_empty(g)-i)==2)
		printf("verification de l'ajout de add_tile");
		break;
	printf("erreur d'ajout de case(add_tile)");

