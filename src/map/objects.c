/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** objects
*/

#include <stdlib.h>
#include "rpg.h"

objects_t *create_objects(sfRenderWindow *window)
{
    objects_t *objects = malloc(sizeof(objects_t));
    objects->background = create_map(window);
    return objects;
}
