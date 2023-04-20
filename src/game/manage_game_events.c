/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** manage_game_events.c
*/

#include "rpg.h"

void manage_key_pressed(instance_t *instance, sfEvent event)
{
    switch (event.key.code) {
        case sfKeyEscape:
            instance->previous_state = (instance->rpg_state == IN_GAME) ?
                IN_GAME : IN_PAUSE_MENU;
            instance->rpg_state = (instance->rpg_state == IN_GAME) ?
                IN_PAUSE_MENU : IN_GAME;
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
