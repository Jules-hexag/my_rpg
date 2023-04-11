/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** manage_game_events.c
*/

#include "rpg.h"

static void manage_key_pressed(instance_t *instance, sfEvent event)
{
    switch (event.key.code) {
        case sfKeyEscape:
            instance->menu_state = IN_PAUSE_MENU;
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
