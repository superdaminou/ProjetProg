#include "grid.h"

struct grid_s {
    tile t_grid[GRID_SIDE][GRID_SIDE];
    int score;
};

grid new_grid () {
    grid g = malloc(sizeof(struct grid_s));
    assert(g != NULL);

    for(int i = 0 ; i < GRID_SIDE ; i++)
    {
        for(int j = 0 ; j < GRID_SIDE ; j++)
        {
            tile t = 0;
            g->t_grid[i][j] = t;
        }
    }
    g->score = 0;
    return g;
}


void delete_grid (grid g) {
    // free(g->grid); inutile dans le cadre d'un tableau statique
    free(g);
}


void copy_grid (grid src, grid dst) {
    for(int i = 0 ; i < GRID_SIDE ; i++)
    {
        for(int j = 0 ; j < GRID_SIDE ; j++)
            dst->t_grid[i][j] = src->t_grid[i][j];
    }
    dst->score = src->score;
}



unsigned long int grid_score (grid g) {
    return g->score;
}


tile get_tile (grid g, int x, int y) {
    assert((0 <= x && x < GRID_SIDE) && (0 <= y && x < GRID_SIDE));
    return g->t_grid[x][y];
}


void set_tile (grid g, int x, int y, tile t) {
    g->t_grid[x][y] = t;
}


bool can_move (grid g, dir d) {
  switch(d) {
    
  case UP:
    for(int i = 0 ; i < GRID_SIDE ; i++) {
	for(int j = 1 ; j < GRID_SIDE ; j++) {
	    if(g->t_grid[i][j] == g->t_grid[i][j-1] || g->t_grid[i][j-1] == 0)
	      return true;
	}
    }
    break;

  case DOWN:
    for(int i = 0 ; i < GRID_SIDE ; i++) {
	for(int j = 0 ; j < GRID_SIDE-1 ; j++){
	  if(g->t_grid[i][j] == g->t_grid[i][j+1] || g->t_grid[i][j+1]=0)
	    return true;
	}
    }
    break;
    
  case LEFT:
    for(int i = 1 ; i < GRID_SIDE ; i++) {
	for(int j = 0 ; j < GRID_SIDE ; j++) {
	  if(g->t_grid[i][j] == g->t_grid[i-1][j] || g->t_grid[i-1][j] == 0)
	    return true;
	}
    }
    break;
    
  case RIGHT:
    for(int i = 0 ; i < GRID_SIDE-1 ; i++) {
	for(int j = 0 ; j < GRID_SIDE ; j++){
	  if(g->t_grid[i][j] == g->t_grid[i+1][j] || g->t_grid[i+1][j] == 0)
	    return true;
	}
    }
    break;
  }
    
  return false;
}


bool game_over (grid g) {
    if (can_move (g, UP))
        return  false;
    if (can_move (g, DOWN))
        return false;
    if (can_move (g, LEFT))
        return false;
    if (can_move (g, RIGHT))
        return false;
    return true;
}
    
    
void do_move (grid g, dir d) {
        assert(can_move(g,d));
        switch(d){
            case UP:
                for(int i=0;i<GRID_SIDE;i++)
                {
                    for(int j=0;j<GRID_SIDE;j++){
                        if(g->t_grid[i][j]!=0)
                        {
                            if(g->t_grid[i][j-1]==0)
                            {
                                g->t_grid[i][j-1]=g->t_grid[i][j];
                                g->t_grid[i][j]=0;
                            }
                            if (g->t_grid[i][j]==g->t_grid[i][j-1])
                            {
                                g->t_grid[i][j-1]+=g->t_grid[i][j];
                                g->t_grid[i][j]=0;
                            }
                        }
                    }
                }
                break;
                
            case LEFT:
                for(int i=1;i<GRID_SIDE;i++)
                {
                    for(int j=0;j<GRID_SIDE;j++)
                    {
                        if(g->t_grid[i][j]!=0)
                        {
                            if(g->t_grid[i-1][j]==0)
                            {
                                g->t_grid[i-1][j]=g->t_grid[i][j];
                                g->t_grid[i][j]=0;
                            }
                            if (g->t_grid[i-1][j]==g->t_grid[i][j])
                            {
                                g->t_grid[i-1][j]+=g->t_grid[i][j];
                                g->t_grid[i][j]=0;
                            }}
                    }
                    
                }
                break;
                
            case DOWN:
                for(int i=0;i<GRID_SIDE;i++)
                {
                    for(int	j=0;j<GRID_SIDE-1;j++)
                    {
                        if(g->t_grid[i][j]!=0)
                        {
                            if(g->t_grid[i][j+1]==0)
                            {
                                g->t_grid[i][j+1]=g->t_grid[i][j];
                                g->t_grid[i][j]=0;
                            }
                            if (g->t_grid[i][j]==g->t_grid[i][j+1])
                            {
                                g->t_grid[i][j+1]+=g->t_grid[i][j];
                                g->t_grid[i][j]=0;
                            }
                            
                        }
                    }
                }
                break;
                
            case RIGHT:
                for(int i=1;i<GRID_SIDE-1;i++)
                {
                    for(int j=0;j<GRID_SIDE;j++)
                    {
                        if(g->t_grid[i][j]!=0)
                        {
                            if(g->t_grid[i+1][j]==0)
                            {
                                g->t_grid[i+1][j]=g->t_grid[i][j];
                                g->t_grid[i][j]=0;
                            }
                            if (g->t_grid[i][j]==g->t_grid[i+1][j])
                            {
                                g->t_grid[i][j+1]+=g->t_grid[i][j];
                                g->t_grid[i][j]=0;
                            }
                        }
                    }
                }
        }
    }
    

// Fonction à optimiser et à compléter
        
void add_tile (grid g) {
  int x = rand_a_b(0, GRID_SIDE);
  int y = rand_a_b(0, GRID_SIDE);
  if (g->t_grid[i][j] == 0)
    return;
}
  
  
        
        
void play (grid g, dir d) {
  if(can_move (g,d))
    do_move (g,d); 
  add_tile(g);
  if(game_over(g))
    return g->score;
}

#endif
