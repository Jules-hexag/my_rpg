/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** render_back_npc.c
*/

#include <SFML/Graphics/RenderWindow.h>
#include "rpg.h"

void render_back_npc(instance_t *instance)
{
    if (instance->player.map_pos.y >= (2 * 64))
        sfRenderWindow_drawSprite(instance->window_params.window,
            instance->npc.sprite, NULL);
}

void render_front_npc(instance_t *instance)
{
    if (instance->player.map_pos.y < (2 * 64))
        sfRenderWindow_drawSprite(instance->window_params.window,
            instance->npc.sprite, NULL);
}
