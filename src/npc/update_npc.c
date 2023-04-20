/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_npc.c
*/

#include <math.h>
#include "rpg.h"

void update_npc(instance_t *instance)
{
    instance->npc.etp_distance =
        sqrtf(powf(instance->player.map_pos.x - instance->npc.pos.x, 2)
        + powf(instance->player.map_pos.y - instance->npc.pos.y, 2));
    if (instance->npc.etp_distance <= 64 && sfKeyboard_isKeyPressed(sfKeyE)) {
        sfMusic_stop(instance->npc.music);
        sfMusic_play(instance->npc.music);
        instance->talked_to_npc = true;
    }
}
