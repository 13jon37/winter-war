/* date = November 11th 2020 3:12 pm */

#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "dynamic_list.h"
#include "scene.h"

typedef struct SCENE_MANAGER_STRUCT {
    int scene_index;
    dynamic_list_T* scenes;
} scene_manager_T;

scene_manager_T* init_scene_manager();

scene_T* get_current_scene_scene_manager(scene_manager_T* sm);

void append_scene_scene_manager(scene_manager_T* sm, scene_T* s);

void tick_scene_manager(scene_manager_T* sm);

void draw_scene_manager(scene_manager_T* sm);

#endif //SCENE_MANAGER_H
