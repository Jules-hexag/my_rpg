/*
** EPITECH PROJECT, 2023
** gen_map
** File description:
** init_player.c
*/

#include "rpg.h"

player_t init_player(void)
{
    player_t player = {0};
    player.pos = (sfVector2f) {48, 48};
    return player;
}
