/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** buttons_funcs
*/

#include "rpg.h"
#include <SFML/Graphics/Types.h>

void depause_game(void *ptr)
{
    instance_t *instance = (instance_t *) ptr;
    instance->previous_state = IN_PAUSE_MENU;
    instance->menu_state = IN_GAME;
}

void save_game(void *ptr)
{
    instance_t *instance = (instance_t *) ptr;
    sfRenderWindow_close(instance->window_params.window);
}

void pause_to_settings(void *ptr)
{
    instance_t *instance = (instance_t *) ptr;
    instance->previous_state = IN_PAUSE_MENU;
    instance->menu_state = IN_SETTINGS;
}
