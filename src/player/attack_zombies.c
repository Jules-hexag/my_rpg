/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** attack_zombies.c
*/

#include "rpg.h"

void attack_zombies(instance_t *instance)
{
    player *player = &instance->player;
    if (player->clocks[TIME_ATTACK] > 0 || !sfKeyboard_isKeyPressed(sfKeySpace))
        return;
    for (int i = 0; i < instance->enemy_count[instance->current_map]; i++) {
        enemy_t *zombie = &instance->enemy[instance->current_map][i];
        if (zombie->is_dead || zombie->etp[ETP_DIST] > 64)
            continue;
        zombie->health.current -= player->stats[STAT_STRENGTH];
    }
    player->clocks[TIME_ATTACK] = player->stats[STAT_ATTACK_SPEED];
}
