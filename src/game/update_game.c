/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_game.c
*/

#include "rpg.h"

void update_game(instance_t *instance)
{
    update_player(instance);
    update_enemy(instance);
    update_bars(instance);
}
