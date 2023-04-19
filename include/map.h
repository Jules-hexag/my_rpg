/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** map.h
*/

#pragma once

typedef struct map_s {
    sfVector2i size;
    sfTexture *tileset;
    sfVertexArray *array;
    sfRenderTexture *render;
    sfSprite *sprite;
    uint8_t **map;
} map_t;
