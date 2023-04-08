/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** display_map.c
*/

#include "rpg.h"

void render_tilemap(instance_t *instance, tilemap_t *tilemap)
{
    sfRenderWindow *window = instance->window_params.window;
    sfRenderStates *states = &tilemap->states;
    sfRenderWindow_drawVertexArray(window, tilemap->array, states);
}

void render_map(instance_t *instances)
{
    tilemap_t *tilemap = instances->map->background;
    render_tilemap(instances, tilemap);
}
