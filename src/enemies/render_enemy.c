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
    for (unsigned i = 0; i < instance->enemy_behind; ++i) {
        enemy_t *enemy = bh_pop(instance->enemy_heap);
        sfRenderWindow_drawSprite(window, enemy->sprite, NULL);
    }
}

void render_front_enemy(instance_t *instance)
{
    sfRenderWindow *window = instance->window_params.window;
    for (unsigned i = instance->enemy_behind;
        i < instance->enemy_count[instance->current_map]
        - instance->dead_enemies; ++i) {
        enemy_t *enemy = bh_pop(instance->enemy_heap);
        if (enemy == NULL)
            continue;
        sfRenderWindow_drawSprite(window, enemy->sprite, NULL);
    }
}
