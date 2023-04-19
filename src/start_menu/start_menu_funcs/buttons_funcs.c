/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** buttons_funcs
*/

#include "rpg.h"

void play_game(instance_t *instance)
{
    instance->menu_state = IN_GAME;
}

void resume_game(instance_t *instance)
{
    sfRenderWindow_close(instance->window_params.window);
}

void tutorial(instance_t *instance)
{
    instance->menu_state = IN_TUTORIAL;
}

void settings(instance_t *instance)
{
    instance->menu_state = IN_SETTINGS;
}

// instance->menu_state = IN_SETTINGS;
void quit_game(instance_t *instance)
{
    sfRenderWindow_close(instance->window_params.window);
}
