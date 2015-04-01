#include "grid.h"

bool test_new_grid (grid g) {
	for(int i = 0 ; i < GRID_SIDE ; i++) {
		for(int j = 0 ; j < GRID_SIDE ; j++) {
			if (get_tile(g,i,j) != 0) {
				return false;
			}
		}
	}
    return true;
}

   
bool test_copy_grid (grid g) {
	grid g1 = new_grid();
	copy_grid(g,g1);
	for(int i = 0 ; i < GRID_SIDE ; i++) {
		for(int j = 0 ; j < GRID_SIDE ; j++) {
			if(get_tile(g,i,j) != get_tile(g1,i,j)) {
				return false;
			}
		}
	}
	if (grid_score(g) == grid_score(g1))
		return true;
	return false;
}


bool test_do_move (grid g, dir d) {
	do_move(g,d);
	switch(d) {
	case UP:
		for(int i = 0 ; i < GRID_SIDE ; i++) {
			int j = 0;
			while (j <= GRID_SIDE-1 || (get_tile(g,i,j) != 0)) {
				j++;
			}
			while (j <= GRID_SIDE-1) {
				if (get_tile(g,i,j) != 0)
					return false;
				j++;
			}
		}
		return true;
				
	case DOWN:
		for(int i = 0 ; i <= GRID_SIDE ; i++) {
			int j = GRID_SIDE-1;
			while(j >= 0 || (get_tile(g,i,j) != 0)) {
				j--;
			}
			while(j >= 0) {
				if (get_tile(g,i,j) != 0)
					return false;
				j--;
			}
		}
		return true;
				

	case RIGHT:
		for(int j = 0 ; j <= GRID_SIDE ; j++) {
			int i = 0;
			while(i < GRID_SIDE || (get_tile(g,i,j) != 0)) {
				i++;
			}
			while(i < GRID_SIDE) {
				if (get_tile(g,i,j) != 0)
					return false;
				i++;
			}
		}
		return true;
		
	case LEFT:
		for(int j = 0 ;j <= GRID_SIDE ; j++) {
			int i = GRID_SIDE-1;
			while(i >= 0 || (get_tile(g,i,j) != 0)) {
				i--;
			}
			while(i >= 0) {
				if (get_tile(g,i,j) != 0)
					return false;
				i--;
			}
		}
		return true;
	}
}


bool test_masque_can_move (grid g, int imin, int imax, int jmin, int jmax, int i1, int j1) {
    if (!(imin >= 0 || imin <= imax || imax <= GRID_SIDE || jmin >= 0 || jmin <= jmax || jmax <= GRID_SIDE))
        return false;
    return true;
}


bool test_can_move(grid g,dir d)
{
	switch(d)
		{
		case UP:
     		return test_masque_can_move(g, 0, GRID_SIDE, 1, GRID_SIDE, 0, -1);
		case DOWN:
     		return test_masque_can_move(g, 0, GRID_SIDE, 0, GRID_SIDE-1, 0,1);	
		case LEFT:
     		return test_masque_can_move(g, 1, GRID_SIDE, 0, GRID_SIDE, -1, 0);
		case RIGHT:
     		return test_masque_can_move(g, 0, GRID_SIDE-1, 0, GRID_SIDE, 1, 0);
		}
}

bool test_add_tile (grid g) {
	int i = count_empty(g);
	add_tile(g);
	if((count_empty(g)+1) == i)
		return true;
	return false;
}


bool test_do_move_all (grid g) {
    dir t[] = {UP, DOWN, LEFT, RIGHT};
	for (int i = 0 ; i < 4 ; i++) {
		if(can_move(g,t[i]) && !test_do_move(g,t[i]))
			return false;
	}
	return true;
}


bool test_can_move_all (grid g) {
    dir t[] = {UP, DOWN, LEFT, RIGHT};
	for (int i = 0 ; i < 4 ; i++) {
		if(can_move(g,t[i]) && !test_can_move(g,t[i]))
			return false;
	}
	return true;
}


int main(){
	grid g = new_grid();

	printf("Test de la fonction create_grid : %s\n", test_new_grid(g)?"True":"False");
	printf("Test de la fonction copy_grid : %s\n", test_copy_grid(g)?"True":"False");
	printf("Test de la fonction can_move : %s\n", test_can_move_all(g)?"True":"False");
	printf("Test de la fonction do_move : %s\n", test_do_move_all(g)?"True":"False");
	printf("Test de la fonction add_tile : %s\n", test_add_tile(g)?"True":"False");
    
	return EXIT_SUCCESS;
}
