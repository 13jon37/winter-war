#include "include/renderwindow.h"
#include "include/actor.h"

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
    
    if (!surface) {
        printf("Failed to load SDL surface.\n");
        exit(1);
    }
    
    r->cursor = SDL_CreateTextureFromSurface(r->renderer, surface);
    SDL_FreeSurface(surface); // free surface to conserve resources because all we want is the texture
    
    // Set mouse positions to 0 because its our "constructor" init
    r->mouse_x = 0;
    r->mouse_y = 0;
    
    return r;
}

void do_render(render_T* r)
{
    SDL_SetRenderDrawColor(r->renderer, 255, 255, 255, 255);
    
    SDL_RenderClear(r->renderer);
    
    // Get mouse pos
    SDL_GetMouseState(&r->mouse_x, &r->mouse_y);
    
    SDL_Rect cursor_rect = { r->mouse_x, r->mouse_y, 64, 64 };
    SDL_RenderCopy(r->renderer, r->cursor, 0, &cursor_rect);
    
    SDL_SetRenderDrawColor(r->renderer, 255, 255, 5, 255);
    
    SDL_RenderPresent(r->renderer);
}

void clean_up(render_T* r)
{
    SDL_DestroyWindow(r->window);
    SDL_DestroyRenderer(r->renderer);
    SDL_DestroyTexture(r->cursor);
    free(r);
    
    SDL_Quit();
}

