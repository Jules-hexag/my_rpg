/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** vertex_operations
*/

#include <SFML/Graphics/VertexArray.h>
#include "rpg.h"

static void get_quad_vertex(sfVertex *quad[4], sfVertexArray *array,
    sfVector2i pos, int size)
{
    for (int i = 0; i < 4; i++)
        quad[i] = sfVertexArray_getVertex(array,
            (pos.y * size + pos.x) * 4 + i);
}

void gen_array_vertex(map_t *map)
{
    for (int y = 0; y < map->size.y; y++)
        for (int x = 0; x < map->size.x; x++) {
            enum tile_type tile_nb = map->map[y][x];
            uint8_t tx = tile_nb % 10;
            uint8_t ty = tile_nb / 10;
            sfVertex *quad[4] = {0};
            get_quad_vertex(quad, map->array, (sfVector2i) {x, y}, map->size.x);
            quad[0]->position = (sfVector2f) {x * 16, y * 16};
            quad[1]->position = (sfVector2f) {((x + 1) * 16), y * 16};
            quad[2]->position = (sfVector2f) {(x + 1) * 16, (y + 1) * 16};
            quad[3]->position = (sfVector2f) {x * 16, (y + 1) * 16};
            quad[0]->texCoords = (sfVector2f) {tx * 16, ty * 16};
            quad[1]->texCoords = (sfVector2f) {(tx + 1) * 16, ty * 16};
            quad[2]->texCoords = (sfVector2f) {(tx + 1) * 16, (ty + 1) * 16};
            quad[3]->texCoords = (sfVector2f) {tx * 16, (ty + 1) * 16};
        }
}
