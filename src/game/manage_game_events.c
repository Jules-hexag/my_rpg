/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** manage_game_events.c
*/

#include "rpg.h"
#include <SFML/Audio/Music.h>

void manage_key_pressed(instance_t *instance, sfEvent event)
{
    switch (event.key.code) {
        case sfKeyEscape:
            instance->previous_state = (instance->rpg_state == IN_GAME) ?
                IN_GAME : IN_PAUSE_MENU;
            instance->rpg_state = (instance->rpg_state == IN_GAME) ?
                IN_PAUSE_MENU : IN_GAME;
            instance->previous_state == IN_GAME ? sfMusic_pause(
                instance->volume.music) : 0;
            break;
        default:
            break;
    }
}

void manage_game_events(instance_t *instance, sfEvent event)
{
    switch (event.type) {
        case sfEvtKeyPressed:
            manage_key_pressed(instance, event);
            break;

        default:
            break;
    }
}
