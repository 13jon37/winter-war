#include "include/renderwindow.h"

// Constant
scene_manager_T* SCENE_MANAGER;

render_T* init_window(const char* window_name, int w, int h)
{
    render_T* r = calloc(1, sizeof(struct RENDER_WINDOW_STRUCT));
    
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Failed to init video. Error: %s\n", SDL_GetError());
        SDL_Quit();
    }
    
    r->window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
    
    if (!r->window) {
        printf("Failed to init window. Error: %s\n", SDL_GetError());
        SDL_Quit();
    }
    
    r->renderer = SDL_CreateRenderer(r->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    return r;
}

void do_render(render_T* r)
{
    SDL_SetRenderDrawColor(r->renderer, 255, 0, 255, 255);
    
    SDL_RenderClear(r->renderer);
    
    SDL_SetRenderDrawColor(r->renderer, 255, 0, 255, 255);
    
    SDL_RenderPresent(r->renderer);
}

void game_loop(render_T* r)
{
    SCENE_MANAGER = init_scene_manager();
    register_scenes(SCENE_MANAGER);
    
    SDL_Event event;
    bool running = true;
    
    while (running)
    {
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) 
                running = false;
        }
        
        do_render(r);
    }
    
    clean_up(r);
}

void clean_up(render_T* r)
{
    SDL_DestroyWindow(r->window);
    SDL_DestroyRenderer(r->renderer);
    SDL_Quit();
}

