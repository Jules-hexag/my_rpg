/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** map
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>
#include "rpg.h"

sfSprite *create_sprite(char *filepath)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, sfTexture_createFromFile(filepath, NULL), true);
    return sprite;
}

static sfSprite **create_tileset(void)
{
    sfSprite **tileset = malloc(sizeof(sfSprite *) * 4);
    tileset[0] = create_sprite("res/tileset/grass.png");
    tileset[1] = create_sprite("res/tileset/tree.png");
    tileset[2] = create_sprite("res/tileset/water.png");
    tileset[3] = NULL;
    return tileset;
}

// si gen_map_blabla fail elle renvoie NULL -> penser à free tout
// (c'est un int**)
sfSprite *create_map(window_t *window_stats)
{
    map_t *all_maps = malloc(sizeof(map_t));
    all_maps->map1 = (int **) generate_int_tab_map("map.txt");
    sfSprite **tileset = create_tileset();
    sfSprite *background = sfSprite_create();
    sfTexture *new_texture = sfTexture_create(window_stats->size.x,
        window_stats->size.y);
    for (int height = 0; height < FILE_MAP_HEIGHT; height++) {
        for (int width = 0; width < FILE_MAP_WIDTH; width++) {
            sfSprite_setPosition(tileset[all_maps->map1[height][width]],
            (sfVector2f) {width * IMG_SIZE, height * IMG_SIZE});
            sfRenderWindow_drawSprite(window_stats->window,
            tileset[all_maps->map1[height][width]], NULL);
        }
    }
    sfTexture_updateFromRenderWindow(new_texture, window_stats->window, 0, 0);
    sfSprite_setTexture(background, new_texture, sfTrue);

    return background;
}
// l. avant return
    // free_arrays(all_maps->map1);
    // free_tileset(tileset);
