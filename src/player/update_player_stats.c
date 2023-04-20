/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_player_stats.c
*/

#include <math.h>
#include "rpg.h"

void update_player_stats(instance_t *instance)
{
    player *player = &instance->player;
    player->stats[STAT_DEFENSE] = powf(1.1f, player->level);
    player->stats[STAT_STRENGTH] = 50 * powf(1.1f, player->level);
    player->stats[STAT_ATTACK_SPEED] = 0.5f * powf(0.9f, player->level);
    player->stats[STAT_SPEED] = 240 * powf(1.1f, player->level);
    player->stats[STAT_REGEN] = 0.5f * powf(1.1f, player->level);
    player->stats[STAT_REGEN_TIME] = 3 * powf(0.9f, player->level);
    player->health.max = 8 * powf(1.1f, player->level);
}
