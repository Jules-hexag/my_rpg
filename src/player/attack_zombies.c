/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** attack_zombies.c
*/

#include "rpg.h"

void attack_zombies(instance_t *instance)
{
    player_t *player = &instance->player;
    if (player->time[TIME_ATTACK] > 0 || !sfKeyboard_isKeyPressed(sfKeySpace))
        return;
    for (int i = 0; i < ENEMY_COUNT; i++) {
        enemy_t *zombie = &instance->enemies[i];
        if (zombie->state == DEAD || zombie->etp[ETP_DIST] > 64)
            continue;
        zombie->health.current -= player->stats[STAT_STRENGTH];
    }
    player->time[TIME_ATTACK] = player->stats[STAT_ATTACK_SPEED];
}
