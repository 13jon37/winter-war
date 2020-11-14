#include <stdio.h>

#include "include/renderwindow.h"

// Constant
scene_manager_T* SCENE_MANAGER;

int main(int argc, char* argv[])
{
    render_T* r = init_window("Winter War", DEF_WIND_WIDTH, DEF_WIND_HEIGHT);
    
    SCENE_MANAGER = init_scene_manager();
    register_scenes(SCENE_MANAGER);
    
    bool running = true;
    
    while (running)
    {
        // Inlcudes quit condtionals and will probably include key events
        running = event_processes();
        
        do_render(r);
    }
    
    clean_up(r);
    
    return 0;
}
