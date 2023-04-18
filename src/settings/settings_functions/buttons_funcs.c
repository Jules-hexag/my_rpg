/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** settings_functions
*/

#include "rpg.h"

void set_windowed(instance_t *instance)
{
    sfRenderWindow *window = instance->window_params.window;
    sfRenderWindow_setSize(window, (sfVector2u) {800, 800});
    instance->window_params.size.x = 800;
    instance->window_params.size.y = 800;
}

void set_fullscreen(instance_t *instance)
{
    sfRenderWindow *window = instance->window_params.window;
    sfRenderWindow_setSize(window, (sfVector2u) {1920, 1080});
    instance->window_params.size.x = 1920;
    instance->window_params.size.y = 1080;
}

void settings_back(instance_t *instance)
{
    instance->menu_state = IN_START_MENU;
}
