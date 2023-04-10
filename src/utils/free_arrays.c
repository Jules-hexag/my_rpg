/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** free_arrays
*/

#include "rpg.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>

void free_arrays(int **map)
{
    for (int i = 0; i < FILE_MAP_HEIGHT; i++) {
        free(map[i]);
    }
    free(map);
}
