/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** callback_bars.c
*/

#include "rpg.h"

void callback_bars(instance_t *instance)
{
    static float old_health = 0;
    static bool play = 0;
    if (instance->player.health.current < 0) {
        init_game(instance);
        instance->rpg_state = IN_START_MENU;
        sfMusic_stop(instance->sounds[1]);
        sfMusic_stop(instance->volume.music);
        sfMusic_play(instance->sounds[1]);
    }
    if (instance->player.health.current >= old_health) {
        sfMusic_pause(instance->sounds[2]);
        play = 0;
    }
    if (instance->player.health.current < old_health && !play) {
        sfMusic_play(instance->sounds[2]);
        play = 1;
    }
    old_health = instance->player.health.current;
}
