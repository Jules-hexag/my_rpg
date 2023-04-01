/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** free_arrays
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>

void free_arrays(int **map)
{
    free(*map);
    free(map);
}

void free_tileset(sfSprite **tileset)
{
    for (int i = 0; i < 3; i++) {
        sfTexture_destroy(sfSprite_getTexture(tileset[i]));
        sfSprite_destroy(tileset[i]);
    }
    free(tileset);
}
