#include "include/actor.h"

actor_T* init_actor(float x, float y)
{
    actor_T* a = calloc(1, sizeof(struct ACTOR_STRUCT));
    
    a->x = x;
    a->y = y;
    
    return a;
}

void update_actor(actor_T* a)
{
    printf("Tick actor\n");
}

void draw_actor(actor_T* a)
{
    printf("Draw actor\n");
}