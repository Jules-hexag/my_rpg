/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** buttons_funcs
*/

#include <SFML/Graphics/RenderWindow.h>
#include "rpg.h"

void play_game(void *ptr)
{
    instance_t *instance = (instance_t *) ptr;
    instance->current_map = MAP_GAME;
    for (unsigned int i = 0; i < instance->enemy_count[MAP_GAME]; i++)
        sfClock_restart(instance->enemy[MAP_GAME][i].clock);
    sfClock_restart(instance->player.clock);
    instance->previous_state = IN_START_MENU;
    instance->menu_state = IN_GAME;
}

void resume_game(void *ptr)
{
    sfRenderWindow_close(((instance_t *) ptr)->window_params.window);
}

void tutorial(void *ptr)
{
    instance_t *instance = (instance_t *) ptr;
    instance->current_map = MAP_TUTORIAL;
    instance->previous_state = IN_START_MENU;
    instance->menu_state = IN_TUTORIAL;
}

void settings(void *ptr)
{
    instance_t *instance = (instance_t *) ptr;
    instance->previous_state = IN_START_MENU;
    instance->menu_state = IN_SETTINGS;
}

void quit_game(void *instance)
{
    sfRenderWindow_close(((instance_t *) instance)->window_params.window);
}
