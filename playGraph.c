#include "grid.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

// Affichage de la grille et du score (version basique à améliorer)

void drawGrid(SDL_Renderer *renderer);
void actualiser(SDL_Renderer *renderer,TTF_Font * font,SDL_Texture * texture,SDL_Surface * message,grid g );

SDL_Color couleur = {255, 255, 255};
SDL_Color textColor = { 255, 255, 255 };

void display (grid g) {
    printf("\nScore : %lu\n\n", grid_score(g));
    for (int j=0; j<GRID_SIDE;j++){
        for (int i = 0 ; i < GRID_SIDE ; i++) {
            if (get_tile(g,i,j) == 0)
            printf("|%4u   ", get_tile(g,i,j));
            else {
                unsigned int n = (unsigned int) get_tile(g,i,j); // downcast pour affichage
                printf("|%4u   ", (unsigned int) pow(2,n));
        }
        puts("|");
    }
    }
    printf("\n\n");
}

void auto_play (grid g)
{
    dir t[] = {UP, DOWN, LEFT, RIGHT};
    int i = 0;
    while (!game_over(g)) {
        i = rand()%4;
        if (can_move(g, t[i]))
        play(g, t[i]);
    }
}

void facto_play (grid g, dir d) {
    play(g, d);
    display(g);
}


int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    //creation de la fenetre:
    SDL_Window* window = SDL_CreateWindow("2048",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,640,SDL_WINDOW_SHOWN);
    //Creation du renderer (actualsation):
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_PRESENTVSYNC);
    
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    
    
    
    
    TTF_Init();
    TTF_Font *font = NULL;
    font = TTF_OpenFont( "../chunkfive.ttf", 28 );
    
    
    SDL_Surface *message = NULL;
    SDL_Surface *screen = NULL;
    
    
    message = TTF_RenderText_Solid( font, "The quick brown fox jumps over the lazy dog", textColor );
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,
                                                         message);
    
    
    srand(time(NULL)); // Initialisation de rand
    
    grid g = new_grid();
    add_tile(g);
    add_tile(g);
    printf("\nUse Z, Q, S, D + enter to play. You can use A to generate a random session.\n\n");
    display(g);
    
    SDL_Event event;
    bool run=true;
    

    
    while (!game_over(g) && run)
    {
        while(SDL_PollEvent(&event)){
            if (event.type==SDL_QUIT)
            {
                run=false;
            }
        
            if(event.type==SDL_KEYDOWN)
            {
                
                
                switch(event.key.keysym.sym)
                    {
                        //cas de la touche echap
                    case SDLK_ESCAPE:
                        run=false;
                        break;
                    case 'a':
                        auto_play(g);
                        display(g);
                        break;
                
                    case SDLK_UP:
                        if (can_move(g, UP))
                        facto_play(g, UP);
                        break;
                
                    case SDLK_DOWN:
                        if (can_move(g, DOWN))
                        facto_play(g, DOWN);
                        break;
                
                    case SDLK_LEFT:
                        if (can_move(g, LEFT))
                        facto_play(g, LEFT);
                        break;
                
                    case SDLK_RIGHT:
                        if (can_move(g, RIGHT))
                            facto_play(g, RIGHT);
                        break;
                
                    default:
                        break;
                }
            }
        }
        SDL_SetRenderDrawColor(renderer, 255,0,0,255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255,255,255,255);
        drawGrid(renderer);
        actualiser(renderer,font,texture,message,g);
        SDL_RenderPresent(renderer);
        

    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    printf("Score final : %lu\n", grid_score(g));
    return EXIT_SUCCESS;
}

void drawGrid(SDL_Renderer *renderer){
    for (int i=0; i<=640; i+=640/GRID_SIDE){
        SDL_SetRenderDrawColor(renderer, 255,255,255,255);
        SDL_RenderDrawLine(renderer,i,0,i,640);
        SDL_RenderDrawLine(renderer,0,i,640,i);
    }
}

void actualiser(SDL_Renderer *renderer,TTF_Font * font,SDL_Texture * texture,SDL_Surface * message,grid g ){
    size_t taillechar=15;
    char c [taillechar];
    
    SDL_Rect taille;
    taille.h=640/GRID_SIDE;
    taille.w=640/GRID_SIDE;
    
    for (int i=0;i<GRID_SIDE;i++){
        for (int j=0;j<GRID_SIDE;j++){
            if (get_tile(g,i,j)!=0){
            int n=pow(2,get_tile(g,i,j));
            snprintf(c,taillechar, "%d",n);
            message = TTF_RenderText_Solid( font, c, textColor );
            SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,
                                                                 message);
            taille.x=i*640/GRID_SIDE;
            taille.y=j*640/GRID_SIDE;
            SDL_RenderCopy(renderer,texture, NULL,&taille);
            SDL_DestroyTexture(texture);
                SDL_FreeSurface(message);
            }
            
        }
    }
}

