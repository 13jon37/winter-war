#include "include/scene_manager.h"

scene_manager_T* init_scene_manager()
{
    scene_manager_T* sm = calloc(1, sizeof(struct SCENE_MANAGER_STRUCT));
    sm->scenes = init_dynamic_list(sizeof(struct SCENE_STRUCT));
    sm->scene_index = 0;
    
    return sm;
}

scene_T* get_current_scene_scene_manager(scene_manager_T* sm)
{
    return (scene_T*) sm->scenes->items[sm->scene_index];
}

void append_scene_scene_manager(scene_manager_T* sm, scene_T* s)
{
    append_dynamic_list(sm->scenes, s);
}