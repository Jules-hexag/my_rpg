/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_game.c
*/

#include "rpg.h"

void update_game(instance_t *instance)
{
    sfView *view = sfRenderWindow_getView(instance->window_params.window);
    sfView_setCenter(view,instance->player.pos);
    sfRenderWindow_setView(instance->window_params.window, view);
}
