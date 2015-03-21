#include "grid.h"

//test des fonctions

void main(grid g){
  grid g=new_grid();
  test_creation_grille(g);
  test_copie(g);
  dir d=UP;
  test_can_move(g,d);
  test_do_move(g,d);
  d=DOWN;
  test_can_move(g,d);
  test_do_move(g,d);
  d=LEFT;
  test_can_move(g,d);
  test_do_move(g,d);
  d=RIGHT;
  test_can_move(g,d);
  test_do_move(g,d);
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

void test_add_tile(grid g){
	int i=count_empty(g);
	add_tile(g);
	if((count_empty(g)-i)==2){
		printf("verification de l'ajout de add_tile");
		break;}
	printf("erreur d'ajout de case(add_tile)");}

void test_do_move(grid g,dir d){
	do_move(grid g,dir d);
	switch(d){
	case UP:
		for(int i=0;j<GRID_SIDE;i++){
			int j=0;
			while(j<=GRID_SIDE-1 || (g->grid[i][j]!=0));){
				j++;}
			while(j<=GRID_SIDE-1){
				if (g->grid[i][j]!=0)
					return("erreur de do_move avec la case [%d][%d]",i,j);}}
			return("verification de do_move");
				
	case DOWN:
		for(int i=0;j<=GRID_SIDE;i++){
			int j=GRID_SIDE-1;
			while(j>=0 || (g->grid[i][j]!=0));){
				j--;}
			while(j>=0){
				if (g->grid[i][j]!=0)
					return("erreur de do_move avec la case [d%][d%d]",i,j);}}
			return("verification de do_move");
				

	case RIGHT:
		for(int j=0;j<=GRID_SIDE;j++){
			int i=0;
			while(i<GRID_SIDE || (g->grid[i][j]!=0));){
				i++;}
			while(i<GRID_SIDE){
				if (g->grid[i][j]!=0)
					return("erreur de do_move avec la case [d%][d%d]",i,j);}}
			return("verification de do_move");
		
	case LEFT:
		for(int j=0;j<=GRID_SIDE;j++){
			int i=GRID_SIDE-1;
			while(i>=0 || (g->grid[i][j]!=0));){
				i--;}
			while(i>=0){
				if (g->grid[i][j]!=0)
					return("erreur de do_move avec la case [d%][d%d]",i,j);}}
			return("verification de do_move");
}
}

void test_can_move(grid g,dir d){
	int c=0;
	switch(d){
     case UP:
     if (masque_can_move(g, 0, GRID_SIDE, 1, GRID_SIDE, 0, -1)==true){
		printf( "mouvement possible vers le haut");
		c=+1;}
	case DOWN:
     if (masque_can_move(g, 0, GRID_SIDE, 0, GRID_SIDE-1, 0, 1)==true){
		printf( "mouvement possible vers le bas");
		c=+1;}
	case LEFT:
     if (masque_can_move(g, 1, GRID_SIDE, 0, GRID_SIDE, -1, 0)==true){
		printf( "mouvement possible vers la gauche");
		c+=1;}
	case RIGHT:
     if (masque_can_move(g, 0, GRID_SIDE-1, 0, GRID_SIDE, 1, 0)==true){
		prinf( "mouvement possible vers la droite");
		c+=1;}
	}
	if (c==0){
		printf("pas de mouvement possible);
		break;
		}
	printf("d% mouvements possibles",c);
	break;
  }

}

static bool masque_can_move (grid g, int imin, int imax, int jmin, int jmax, int i1, int j1) {
  for (int i = imin ; i < imax ; i++) {
    for (int j = jmin ; j < jmax ; j++) {
      if(g->t_grid[i][j] == g->t_grid[i+i1][j+j1] || g->t_grid[i+i1][j+j1] == 0)
          return true;
    }
  }
  return false;
}
