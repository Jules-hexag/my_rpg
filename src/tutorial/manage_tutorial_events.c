/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** manage_tutorial_events
*/

#include "rpg.h"

void manage_tutorial_events(instance_t *instance, sfEvent event)
{
    switch (event.type) {
        case sfEvtKeyPressed:
            manage_key_pressed(instance, event);
            break;

        default:
            break;
    }
}