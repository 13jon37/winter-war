#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "program_options.h"
#include "scene_manager.h"
#include "scene_registry.h"

#define DEF_WIND_WIDTH 800
#define DEF_WIND_HEIGHT 600

typedef struct RENDER_WINDOW_STRUCT {
    SDL_Window* window;
    SDL_Renderer* renderer;
    const char* cursor_name;
    SDL_Texture* cursor;
} render_T;

// "Methods"

// Constructor
render_T* init_window(const char* window_name, int w, int h);

void do_render(render_T* r);

void game_loop(void);

void clean_up(render_T* r);

#endif
