/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_instance.c
*/

#include "rpg.h"

void update_instance(instance_t *instance)
{
    sfRenderWindow *window = instance->window_params.window;
    instance->window_params.size = sfRenderWindow_getSize(window);
    instance->window_params.view = (sfView *) sfRenderWindow_getView(window);
}
