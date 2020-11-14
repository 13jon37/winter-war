#include "include/renderwindow.h"
#include "include/game_simulation.h"

// Constant
scene_manager_T* SCENE_MANAGER;

render_T* init_window(const char* window_name, int w, int h)
{
    render_T* r = calloc(1, sizeof(struct RENDER_WINDOW_STRUCT));
    
    /* NOTE(1337): C library function void *calloc(size_t nitems, size_t size) 
    calloc allocates requested memory and returns a pointer to it. Calloc sets allocated memory to zero, malloc does not. */
    
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Failed to init video. Error: %s\n", SDL_GetError());
        exit(1);
    }
    
    if (!IMG_Init(IMG_INIT_PNG)) {
        printf("Failed to init IMG. Error: %s\n", SDL_GetError());
        exit(1);
    }
    
    r->window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
    
    if (!r->window) {
        printf("Failed to init window. Error: %s\n", SDL_GetError());
        exit(1);
    }
    
    r->renderer = SDL_CreateRenderer(r->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    SDL_ShowCursor(SDL_DISABLE); // Disable cursor so we can render our own
    
    // Initialize cursor
    r->cursor_name = "img/crosshair.png";
    
    // Load in cursor png
    SDL_Surface* surface = IMG_Load(r->cursor_name);
    
    if (!surface)
        printf("Failed to load SDL surface.\n");
    
    r->cursor = SDL_CreateTextureFromSurface(r->renderer, surface);
    SDL_FreeSurface(surface); // free surface to conserve resources because all we want is the texture
    
    return r;
}

void do_render(render_T* r)
{
    SDL_SetRenderDrawColor(r->renderer, 255, 255, 255, 255);
    
    SDL_RenderClear(r->renderer);
    
    //SDL_SetRenderDrawColor(r->renderer, 255, 255, 255, 255);
    
    int mouse_x, mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    
    SDL_Rect cursor_rect = { mouse_x, mouse_y, 64, 64 };
    SDL_RenderCopy(r->renderer, r->cursor, 0, &cursor_rect);
    
    SDL_RenderPresent(r->renderer);
}

void game_loop(void)
{
    render_T* r = init_window("Winter War", DEF_WIND_WIDTH, DEF_WIND_HEIGHT);
    
    SCENE_MANAGER = init_scene_manager();
    register_scenes(SCENE_MANAGER);
    
    bool running = true;
    
    while (running)
    {
        // Inlcudes quit condtionals and will probably include key events
        running = event_processes();
        
        do_render(r);
    }
    
    clean_up(r);
}

void clean_up(render_T* r)
{
    SDL_DestroyWindow(r->window);
    SDL_DestroyRenderer(r->renderer);
    SDL_DestroyTexture(r->cursor);
    free(r);
    SDL_Quit();
}

