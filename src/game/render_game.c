/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** render_game.c
*/

#include "rpg.h"

void render_game(instance_t *instance)
{
    sfRenderWindow *window = instance->window_params.window;
    render_map(instance);
}
