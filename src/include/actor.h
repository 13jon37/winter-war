/* date = November 11th 2020 2:33 pm */

#ifndef ACTOR_H
#define ACTOR_H

#include "renderwindow.h"

typedef struct ACTOR_STRUCT {
    float x, y;
    SDL_Renderer* renderer;
} actor_T;

actor_T* init_actor(float x, float y, render_T* r);

void tick_actor(actor_T* a);

void draw_actor(actor_T* a);

#endif //ACTOR_H
