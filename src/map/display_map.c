/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** display_map.c
*/

#include "rpg.h"

void map_display(instance_t *instance)
{
    sfRenderWindow_drawSprite(instance->window, instance->map->background, NULL);
}
