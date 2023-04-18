/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** render_game.c
*/

#include "rpg.h"

void render_game(instance_t *instance)
{
    render_game_map(instance);
    render_back_enemy(instance);
    render_player(instance);
    render_front_enemy(instance);
    render_bars(instance);
}
