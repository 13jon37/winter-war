#include "include/actor.h"

actor_T* init_actor(float x, float y, render_T* r)
{
    actor_T* a = calloc(1, sizeof(struct ACTOR_STRUCT));
    
    a->x = x;
    a->y = y;
    
    a->renderer = r->renderer;
    
    return a;
}

void tick_actor(actor_T* a)
{
    printf("Tick actor\n");
}

void draw_actor(actor_T* a)
{
    printf("Draw actor\n");
    
    SDL_Rect rect = { a->x, a->y, 32, 32 };
    SDL_RenderFillRect(a->renderer, &rect);
}