/* date = November 11th 2020 3:12 pm */

#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "dynamic_list.h"
#include "scene.h"
#include "scene_manager.h"

typedef struct SCENE_MANAGER_STRUCT {
    int scene_index;
    dynamic_list_T* scenes;
} scene_manager_T;

scene_manager_T* init_scene_manager();

scene_T* get_current_scene_scene_manager(scene_manager_T* sm);

void append_scene_scene_manager(scene_manager_T* sm, scene_T* s);

#endif //SCENE_MANAGER_H
