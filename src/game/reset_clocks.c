/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** reset_clocks.c
*/

#include "rpg.h"

void reset_clocks(instance_t *instance)
{
    for (unsigned int i = 0; i < instance->enemy_count[MAP_GAME]; i++)
        sfClock_restart(instance->enemy[MAP_GAME][i].clock);
    sfClock_restart(instance->player.clock);
}
