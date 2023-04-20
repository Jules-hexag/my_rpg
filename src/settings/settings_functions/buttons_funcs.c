/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** settings_functions
*/

#include "rpg.h"

void set_windowed(void *ptr)
{
    instance_t *instance = (instance_t *) ptr;
    sfRenderWindow *window = instance->window_params.window;
    sfRenderWindow_setSize(window, (sfVector2u) {800, 800});
    instance->window_params.size.x = 800;
    instance->window_params.size.y = 800;
}

void set_fullscreen(void *ptr)
{
    instance_t *instance = (instance_t *) ptr;
    sfRenderWindow *window = instance->window_params.window;
    sfRenderWindow_setSize(window, (sfVector2u) {1920, 1080});
    instance->window_params.size.x = 1920;
    instance->window_params.size.y = 1080;
}

void settings_back(void *ptr)
{
    instance_t *instance = (instance_t *) ptr;
    instance->menu_state = instance->previous_state;
    instance->previous_state = IN_SETTINGS;
}
