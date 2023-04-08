/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** map
*/

#include <SFML/Graphics/Texture.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/VertexArray.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Graphics/RenderStates.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "rpg.h"


void get_quad_vertex(sfVertex *quad[4], sfVertexArray *array, sfVector2i pos,
    int size)
{
    for (int i = 0; i < 4; i++)
        quad[i] = sfVertexArray_getVertex(array, (pos.y * size + pos.x) * 4 + i);
}

void init_tilemap_vertex(tilemap_t *tilemap, sfVector2i size, uint8_t **map)
{
    for (int y = 0; y < size.y; y++)
        for (int x = 0; x < size.x; x++) {
            enum tile_type tile_nb = map[y][x];
            uint8_t tx = tile_nb % 10;
            uint8_t ty = tile_nb / 10;
            sfVertex *quad[4] = {0};
            get_quad_vertex(quad, tilemap->array, (sfVector2i) {x, y}, size.x);
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

tilemap_t *init_tilemap(sfVector2i size, uint8_t **map, char tileset[])
{
    static tilemap_t tilemap = {0};
    tilemap.tileset = sfTexture_createFromFile(tileset, NULL);
    tilemap.array = sfVertexArray_create();
    tilemap.states.transform = sfTransform_Identity;
    tilemap.states.shader = NULL;
    tilemap.states.texture = tilemap.tileset;
    tilemap.states.blendMode = sfBlendAdd;
    sfVertexArray_setPrimitiveType(tilemap.array, sfQuads);
    sfVertexArray_resize(tilemap.array, size.x * size.y  * 4);
    init_tilemap_vertex(&tilemap, size, map);
    return &tilemap;
}

map_t init_map_from_file(char file[])
{
    map_t map = {0};
    int map_file = open(file, O_RDONLY);
    read(map_file, &map, sizeof(map_t));
    map.map = malloc(sizeof(char *[map.size.y]));
    map.map[0] = malloc(sizeof(char [map.size.y * (map.size.x + 1)]));
    read(map_file, map.map[0], map.size.y * (map.size.x + 1));
    for (int i = 1; i < map.size.y; i++)
        map.map[i] = &map.map[0][i * (map.size.x + 1)];
    close(map_file);
    return map;
}

/**
 * @brief call the int** map function and generate the tileset calling
 * appropriate functions
 *
 * @param window_params to generate the texture
 * @return map_t* structure filled with int** map & graphic background
 */
map_t init_map(void)
{
    map_t map = init_map_from_file("res/maps/map");
    map.background = init_tilemap(map.size, map.map, "res/tileset.png");

    return map;
}
