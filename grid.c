#include "grid.h"


struct grid_s
{
    tile t_grid[GRID_SIDE][GRID_SIDE];
    int score;
};



grid new_grid()
{
    grid grid=malloc(sizeof(grid));
    grid->score=0;
    return grid;
}

void delete_grid(grid g)
{
    free (g);
}

void copy_grid(grid src,grid dst)
{
    
}