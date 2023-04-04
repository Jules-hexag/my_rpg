/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** display_map.c
*/

#include "rpg.h"

void map_display(instance_t *instances)
{
    sfRenderWindow_drawSprite(instances->window_stats->window,
        instances->map->background, NULL);
}
