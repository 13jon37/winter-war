#include "include/scene.h"
#include "include/actor.h"

scene_T* init_scene()
{
    scene_T* s = calloc(1, sizeof(struct SCENE_STRUCT));
    
    s->actors = init_dynamic_list(sizeof(struct ACTOR_STRUCT));
    
    return s;
}

void tick_scene(scene_T* s)
{
    for (int i = 0; i < s->actors->size; i++) {
        update_actor((actor_T*)s->actors->items[i]);
    }
}

void draw_scene(scene_T* s)
{
    for (int i = 0; i < s->actors->size; i++) {
        update_actor((actor_T*)s->actors->items[i]);
    }
}