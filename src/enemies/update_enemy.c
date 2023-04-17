/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_enemy.c
*/

#include <math.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/RectangleShape.h>
#include "binary_heap.h"
#include "rpg.h"


static void update_enemy_render_stage(instance_t *instance, enemy_t *enemy)
{
    if (enemy->state == DEAD)
        return;
    bh_append(instance->enemy_heap, enemy);
    if (enemy->pos.y < instance->player.map_pos.y)
        instance->enemy_behind++;
}

static void update_enemy_to_player_dist(instance_t *instance, enemy_t *enemy)
{
    if (enemy->state == DEAD)
        return;
    enemy->player_dist = sqrtf(powf(enemy->pos.x - instance->player.map_pos.x, 2) + powf(enemy->pos.y - instance->player.map_pos.y, 2));
    if (enemy->player_dist <= 248)
        bh_append(instance->enemy_heap, enemy);
}

static void move_enemy(instance_t *instance, enemy_t *enemy, int dtime, struct queue *queue)
{
    float speed = ENEMY_SPEED * dtime / (1000.f / 60.f);
    player_t *player = &instance->player;
    if (sfFloatRect_intersects(&enemy->bbox, &player->bbox, NULL)) {
        player->health.current-= 0.01;
        return;
    }
    for (int i = 0; i < queue->last; ++i)
        if (sfFloatRect_intersects(&enemy->bbox,&((enemy_t *) queue->queue[i])->bbox, NULL))
            return;
    if (enemy->player_dist > 248)
        return;
    sfVector2f d_pos = {player->map_pos.x - enemy->pos.x,
       player->map_pos.y - enemy->pos.y};
    sfVector2f move = {d_pos.x / enemy->player_dist * speed,
        d_pos.y / enemy->player_dist * speed};
    enemy->pos.x += move.x;
    enemy->pos.y += move.y;
    enemy->bbox = (sfFloatRect) {enemy->pos.x - 32, enemy->pos.y - 32, 64, 64};
    sfSprite_setPosition(enemy->sprite, enemy->pos);
    queue->queue[queue->last++] = enemy;
}

void update_enemy(instance_t *instance)
{
    struct queue queue = {0};
    enemy_t *enemy;
    instance->enemy_heap->value = &enemy_value;
    for (int i = 0; i < ENEMY_COUNT; ++i)
        update_enemy_to_player_dist(instance, &instance->enemies[i]);
    while ((enemy = bh_pop(instance->enemy_heap))) {
        int dtime = sfTime_asMilliseconds(sfClock_getElapsedTime(enemy->sprite_clock));
        move_enemy(instance, enemy, dtime, &queue);
    }
    instance->enemy_heap->value = &enemy_pos;
    instance->enemy_behind = 0;
    for (int i = 0; i < ENEMY_COUNT; ++i) {
        sfClock_restart(instance->enemies[i].sprite_clock);
        update_enemy_render_stage(instance, &instance->enemies[i]);
    }
}
