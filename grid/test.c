#include "grid.h"

//test des fonctions



bool test_creation_grille(grid g)
{
  if(grid_score(g)==0)
    printf("score initialisé à 0");
  for(int i=0;i<GRID_SIDE;i++)
  {
    for(int j=0;j<GRID_SIDE;j++)
    {
      if(get_tile(g,i,j)!=0)
      {
		return false;
      }
      
    }
  }
    return true;
}

   
bool test_copie(grid g)
{
  grid g1=new_grid();
  copy_grid(g,g1);
  for(int i = 0 ; i < GRID_SIDE ; i++)
  {
    for(int j = 0 ; j < GRID_SIDE ; j++)
    {
      if(get_tile(g,i,j) != get_tile(g1,i,j)){
		return false;
      }
    }
  }
  if(grid_score(g)==grid_score(g1))
    return true;
  return false;
}

bool test_add_tile(grid g)
{
	int i=count_empty(g);
	add_tile(g);
	if((count_empty(g)-i)==2)
		return true;
	return false;
}

bool test_do_move(grid g,dir d)
{
	do_move(g,d);
	switch(d)
    {
	case UP:
		for(int i=0;i<GRID_SIDE;i++)
        {
			int j=0;
			while(j<=GRID_SIDE-1 || (get_tile(g,i,j)!=0))
            {
				j++;
            }
			while(j<=GRID_SIDE-1)  // est ce que c'est bien ca que tu voulais ecrire?
            {
				if (get_tile(g,i,j)!=0)
					return false;
                j++;
            }
        }
			return true;
				
	case DOWN:
		for(int i=0;i<=GRID_SIDE;i++)
        {
			int j=GRID_SIDE-1;
			while(j>=0 || (get_tile(g,i,j)!=0))
            {
				j--;
            }
			while(j>=0)
            {
				if (get_tile(g,i,j)!=0)
					return false;
                j--;
            }
        }
			return true;
				

	case RIGHT:
		for(int j=0;j<=GRID_SIDE;j++)
        {
			int i=0;
			while(i<GRID_SIDE || (get_tile(g,i,j)!=0))
            {
				i++;
            }
			while(i<GRID_SIDE)
            {
				if (get_tile(g,i,j)!=0)
					return false;
            }
        }
			return true;
		
	case LEFT:
		for(int j=0;j<=GRID_SIDE;j++)
        {
			int i=GRID_SIDE-1;
			while(i>=0 || (get_tile(g,i,j)!=0))
            {
				i--;
            }
			while(i>=0)
            {
				if (get_tile(g,i,j)!=0)
					return false;
                i--;
            }
        }
			return true;
}
}


/*pas forcement nessesaire je suis pas sur mais je sais pas trop quoi mettre pour tester  */
bool test_masque_can_move (grid g, int imin, int imax, int jmin, int jmax, int i1, int j1) {
    if(!(imin>=0||imin<=imax||imax<=GRID_SIDE||jmin>=0||jmin<=jmax||jmax<=GRID_SIDE))
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
     		return test_masque_can_move(g, 0, GRID_SIDE, 0, GRID_SIDE-1,0,1);	
	case LEFT:
     		return test_masque_can_move(g, 1, GRID_SIDE, 0, GRID_SIDE, -1, 0);
	case RIGHT:
     		return test_masque_can_move(g,0,GRID_SIDE-1,0,GRID_SIDE,1,0);
	}
  }

int  main(){
    grid g=new_grid();
    return test_creation_grille(g);
    return test_copie(g);
    dir d=UP;
    return test_can_move(g,d);
    if(can_move(g,d))
        return test_do_move(g,d);
    d=DOWN;
    return test_can_move(g,d);
    if(can_move(g,d))
        return test_do_move(g,d);
    d=LEFT;
    return test_can_move(g,d);
    if(can_move(g,d))
        return test_do_move(g,d);
    d=RIGHT;
    return test_can_move(g,d);
    if(can_move(g,d))
        return test_do_move(g,d);
    return test_add_tile(g);
    
    return 0;
}
