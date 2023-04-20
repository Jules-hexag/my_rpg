/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** buttons_funcs
*/

#include <SFML/Audio/Music.h>
#include <SFML/Audio/Types.h>
#include <stdio.h>
#include <SFML/Graphics/Types.h>
#include "rpg.h"

void depause_game(void *ptr)
{
    instance_t *instance = (instance_t *) ptr;
    reset_clocks(instance);
    sfMusic_play(instance->volume.music);
    instance->previous_state = IN_PAUSE_MENU;
    instance->rpg_state = IN_GAME;
}

void pause_to_settings(void *ptr)
{
    instance_t *instance = (instance_t *) ptr;
    instance->previous_state = IN_PAUSE_MENU;
    instance->rpg_state = IN_SETTINGS;
}
