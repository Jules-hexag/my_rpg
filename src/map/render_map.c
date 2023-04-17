/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** display_map.c
*/

#include <SFML/Graphics/RenderTexture.h>
#include "rpg.h"

void render_tutorial_map(instance_t *instance)
{
    sfRenderWindow *window = instance->window_params.window;
    sfRenderWindow_drawSprite(window, instance->map[MAP_TUTORIAL].sprite, NULL);
}

void render_game_map(instance_t *instance)
{
    sfRenderWindow *window = instance->window_params.window;
    sfRenderWindow_drawSprite(window, instance->map[MAP_GAME].sprite, NULL);
}
