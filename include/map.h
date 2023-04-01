/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** map.h
*/

#pragma once

#include "rpg.h"

enum tile_type {
    TILE_GRASS,
    TILE_TREE,
    TILE_WATER,
};

void map_display(instance_t *instance);
