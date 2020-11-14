#include "include/scene.h"
#include "include/actor.h"

// Credits to Ianertson

scene_T* init_scene(render_T* r)
{
    scene_T* s = calloc(1, sizeof(struct SCENE_STRUCT));
    
    s->actors = init_dynamic_list(sizeof(struct ACTOR_STRUCT));
    
    append_dynamic_list(s->actors, init_actor(0.0f, 0.0f, r));
    
    return s;
}

void tick_scene(scene_T* s)
{
    for (int i = 0; i < s->actors->size; i++) {
        tick_actor((actor_T*)s->actors->items[i]);
    }
}

void draw_scene(scene_T* s)
{
    for (int i = 0; i < s->actors->size; i++) {
        draw_actor((actor_T*)s->actors->items[i]);
    }
}