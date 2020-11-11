#include "include/renderwindow.h"


render_T* init_window(const char* window_name, int w, int h)
{
    render_T* r = calloc(1, sizeof(struct RENDER_WINDOW_STRUCT));
    
    r->window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
    
    if (!r->window)
        printf("Failed to init window. Error: %s\n", SDL_GetError());
    
    r->renderer = SDL_CreateRenderer(r->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    return r;
}

void clean_up(render_T* r)
{
    SDL_DestroyWindow(r->window);
    SDL_DestroyRenderer(r->renderer);
}
