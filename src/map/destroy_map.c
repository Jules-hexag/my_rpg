/*
** EPITECH PROJECT, 2023
** gen_map
** File description:
** destroy_map.c
*/

#include <stdlib.h>
#include <SFML/Graphics/VertexArray.h>
#include <SFML/Graphics/Texture.h>
#include "rpg.h"

void destroy_map(map_t *map)
{
    free(map->map[0]);
    free(map->map);
    sfVertexArray_destroy(map->background->array);
    sfTexture_destroy(map->background->tileset);
}
