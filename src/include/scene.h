/* date = November 11th 2020 2:42 pm */

#ifndef SCENE_H
#define SCENE_H

#include "dynamic_list.h"

typedef struct SCENE_STRUCT {
    dynamic_list_T* actors;
} scene_T;

scene_T* init_scene();

void tick_scene(scene_T* s);

void draw_scene(scene_T* s);

#endif //SCENE_H
