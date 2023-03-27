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
sfSprite *create_map(sfRenderWindow *window)
{
    maps_t *all_maps = malloc(sizeof(maps_t));
    all_maps->map1 = gen_map_tab("map.txt");
    sfSprite **tileset = create_tileset();
    sfSprite *background = sfSprite_create();
    sfTexture *new_texture = sfTexture_create(WIN_WIDTH, WIN_HEIGHT);
    for (int height = 0; height < FILE_HEIGHT; height++) {
        for (int width = 0; width < FILE_WIDTH; width++) {
            sfSprite_setPosition(tileset[all_maps->map1[height][width]],
            (sfVector2f) {width * IMG_SIZE, height * IMG_SIZE});
            sfRenderWindow_drawSprite(window,
            tileset[all_maps->map1[height][width]], NULL);
        }
    }
    sfTexture_updateFromRenderWindow(new_texture, window, 0, 0);
    sfSprite_setTexture(background, new_texture, sfTrue);

    free_arrays(all_maps->map1);
    free_tileset(tileset);
    return background;
}
