#include "grid.h"


struct grid_s
{
    tile t_grid[GRID_SIDE][GRID_SIDE];
    int score;
};

grid new_grid ()
{
    grid g=malloc(sizeof(grid));
    assert(g!=NULL);
    for(int i=0;i<GRID_SIDE;i++)
    {
        for(int j=0;i<GRID_SIDE;i++)
        {
            tile t=0;
            g->grid[i][j]=t;
        }
    }
    g->score=0;
    return g;
}


void delete_grid (grid g)
{
  free(g->grid);
  free(g);
}



void copy_grid (grid src, grid dst)
{
  for(int i=0;i<GRID_SIDE;i++)
      {
	    for(int j=0;i<GRID_SIDE;i++)
	      dst->grid[i][j]= src->grid[i][j];
      }
  dst->score=src->score;
}



unsigned long int grid_score (grid g)
{
  return g->score;
}


 tile get_tile (grid g, int x, int y){
   assert((0<=x<GRID_SIDE)&&(0<= y <GRID_SIDE));
   if(g->grid[x][y])
     return vide;
   else
     return 2**i;
 }


 void set_tile (grid g, int x, int y, tile t){
   g[x][y]=t;
 }
   
   
bool can_move (grid g, dir d){

  switch(d){
    
  case UP:
    for(int i=0;i<GRID_SIDE;i++)
      {
	for(int j=1;i<GRID_SIDE;i++){
	  if((g[i][j]==g[i][j-1])||(g[i][j-1]=0)){
	    return true;
	  }
	}
      }
    break;
    
  case LEFT:
    for(int i=1;i<GRID_SIDE;i++)
      {
	for(int j=0;i<GRID_SIDE;i++){
	  if((g[i][j]==g[i-1][j])||(g[i-1][j-1]=0)){
	    return true;
	  }
	}
      }
    break;
      
  case DOWN:
    for(int i=0;i<GRID_SIDE;i++)
      {
	for(int j=0;i<GRID_SIDE-1;i++){
	  if((g[i][j]==g[i][j+1])||(g[i-1][j+1]=0)){
	    return true;
	  }
	}
      }
    break;
  case RIGHT:
    for(int i=1;i<GRID_SIDE;i++)
      {
	for(int j=0;i<GRID_SIDE;i++){
	  if((g[i][j]==g[i+1][j])||(g[i+1][j-1]=0)){
	    return true;
	    
	  }
	}
      }
    
  }
  break;
  return false;
  
}


 bool game_over (grid g)
 {
   switch(d)
   case UP:
      if (can_move (g,d))
	return false;
   break;
   case DOWN:
     if (can_move (g,d))
       return false;
     break;
    case LEFT:
      if (can_move (g,d))
	return false;
      break;
 case RIGHT:
       if (can_move (g,d))
	 return false;
       break;
 }
return true;
 }
   


void do_move (grid g, dir d){
  assert(can_move(g,d)==true);
}


 void add_tile (grid g);


 void play (grid g, dir d);
