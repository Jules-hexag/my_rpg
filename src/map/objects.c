/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** objects
*/

#include <stdlib.h>
#include "rpg.h"

instance_t *create_instance(sfRenderWindow *window)
{
    instance_t *instance = malloc(sizeof(instance_t));

    instance->window = window;
    instance->map = malloc(sizeof(map_t));
    instance->map->background = create_map(window);

    return instance;
}
