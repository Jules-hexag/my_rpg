/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** display_map.c
*/

#include <SFML/Graphics/RenderTexture.h>
#include "rpg.h"

void render_map(instance_t *instances)
{
    sfRenderWindow *window = instances->window_params.window;
    sfRenderWindow_drawSprite(window, instances->map[0].sprite, NULL);
}
