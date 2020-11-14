#include "include/scene_registry.h"

/* All scenes go here. */

void register_scenes(scene_manager_T* sm)
{
    printf("Registering Scenes\n");
    /* TODO(1337): 
* Register main menu scene
 * Register game scene
*/
    
    append_scene_scene_manager(sm, init_scene());
}