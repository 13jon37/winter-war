#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define DEF_WIND_WIDTH 800
#define DEF_WIND_HEIGHT 600

typedef struct RENDER_WINDOW_STRUCT {
    SDL_Window* window;
    SDL_Renderer* renderer;
} render_T;

// "Methods"

// Constructor
render_T* init_window(const char* window_name, int w, int h);

void clean_up(render_T* r);

#endif
