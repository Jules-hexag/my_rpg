/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** render_game.c
*/

#include "rpg.h"

void render_game(instance_t *instance)
{
    render_map(instance);
    render_player(instance);
    render_bars(instance);
}
