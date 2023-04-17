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
#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Graphics/Sprite.h>
#include "rpg.h"

sfSprite *gen_tilemap_sprite(map_t *map)
{
    map->render = sfRenderTexture_create(map->size.x * 16,
        map->size.y * 16, sfFalse);
    sfSprite *sprite = sfSprite_create();
    sfRenderStates states = {sfBlendAdd, sfTransform_Identity,map->tileset,
        NULL};
    sfRenderTexture_drawVertexArray(map->render, map->array, &states);
    sfRenderTexture_display(map->render);
    sfSprite_setTexture(sprite, sfRenderTexture_getTexture(map->render),
        sfTrue);
    sfSprite_setScale(sprite, (sfVector2f) {4, 4});
    return sprite;
}

sfVertexArray *init_array(map_t *map)
{
    sfVertexArray *array = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(array, sfQuads);
    sfVertexArray_resize(array, map->size.x * map->size.y  * 4);

    return array;
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
 * @return map_t* structure filled with int** map & graphic tilemap
 */
map_t init_map(char *struct_path)
{
    map_t map = init_map_from_file(struct_path);
    map.tileset = sfTexture_createFromFile("res/tileset.png", NULL);
    map.array = init_array(&map);
    gen_array_vertex(&map);
    map.sprite = gen_tilemap_sprite(&map);

    return map;
}
