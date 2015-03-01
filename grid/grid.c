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
            g->t_grid[i][j]=t;
        }
    }
    g->score=0;
    return g;
}


void delete_grid (grid g)
{
  //free(g->t_grid); pas besoin t_grid est un tableau statique
  free(g);
}



void copy_grid (grid src, grid dst)
{
  for(int i=0;i<GRID_SIDE;i++)
      {
	    for(int j=0;i<GRID_SIDE;i++)
	      dst->t_grid[i][j]= src->t_grid[i][j];
      }
  dst->score=src->score;
}



unsigned long int grid_score (grid g)
{
  return g->score;
}


 tile get_tile (grid g, int x, int y) //A finir
{
   assert((0<=x && x<GRID_SIDE)&&(0<= y && y<GRID_SIDE)); //attention au condition 0<x<10 n'existe pas il faut faire 0<x && x<10
   if(g->t_grid[x][y])
     return NULL;   // a revoir et le precedent return vide n'exite pas car vide ne signifie rien
   else
     return 2*i;  //que signifie i?
 }


 void set_tile (grid g, int x, int y, tile t){
   g->t_grid[x][y]=t;
 }
   
   
bool can_move (grid g, dir d){

  switch(d)
    {
    
        case UP:
            for(int i=0;i<GRID_SIDE;i++)
            {
                for(int j=1;i<GRID_SIDE;j++)
                {
                    if((g->t_grid[i][j]==g->t_grid[i][j-1])||(g->t_grid[i][j-1]=0))
                    {
                        return true;
                    }
                }
            }
            break;
    
        case LEFT:
            for(int i=1;i<GRID_SIDE;i++)
            {
                for(int j=0;i<GRID_SIDE;j++)
                {
                    if((g->t_grid[i][j]==g->t_grid[i-1][j])||(g->t_grid[i-1][j-1]=0))
                    {
                        return true;
                    }
                }
            }
            break;
      
        case DOWN:
            for(int i=0;i<GRID_SIDE;i++)
            {
                for(int j=0;i<GRID_SIDE-1;j++)
                {
                    if((g->t_grid[i][j]==g->t_grid[i][j+1])||(g->t_grid[i-1][j+1]=0))
                    {
                        return true;
                    }
                }
            }
            break;
        case RIGHT:
            for(int i=1;i<GRID_SIDE;i++)
            {
                for(int j=0;i<GRID_SIDE;j++)
                {
                    if((g->t_grid[i][j]==g->t_grid[i+1][j])||(g->t_grid[i+1][j-1]=0))
                    {
                        return true;
                    }
                }
            }
            break;
    }
  
  return false;
  
}


 bool game_over (grid g)   // A revoir
 {
   switch(d) // d? il n'existe pas pour le moment
     {
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
   


void do_move (grid g, dir d){    //A finir
  assert(can_move(g,d)==true);
}


 void add_tile (grid g);


 void play (grid g, dir d);
