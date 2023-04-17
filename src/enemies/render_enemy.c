/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** render_enemy.c
*/

#include "rpg.h"

void render_back_enemy(instance_t *instance)
{
    sfRenderWindow *window = instance->window_params.window;
    for (int i = 0; i < ENEMY_COUNT; ++i) {
        if (instance->enemies[i].state != DEAD && instance->enemies[i].layer == BACK)
            sfRenderWindow_drawSprite(window, instance->enemies[i].sprite, NULL);
    }
}

void render_front_enemy(instance_t *instance)
{
    sfRenderWindow *window = instance->window_params.window;
    for (int i = 0; i < ENEMY_COUNT; ++i) {
        if (instance->enemies[i].state != DEAD && instance->enemies[i].layer == FRONT)
            sfRenderWindow_drawSprite(window, instance->enemies[i].sprite, NULL);
    }
}
