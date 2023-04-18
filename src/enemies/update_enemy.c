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
    enemy->player_dist = sqrtf(powf(enemy->pos.x - instance->player.map_pos.x,
        2) + powf(enemy->pos.y - instance->player.map_pos.y, 2));
    if (enemy->player_dist <= 248)
        bh_append(instance->enemy_heap, enemy);
}

static void update_enemy_pos(enemy_t *enemy, float dtime, player_t *player)
{
    float speed = ENEMY_SPEED * dtime;
    sfVector2f d_pos = {player->map_pos.x - enemy->pos.x,
        player->map_pos.y - enemy->pos.y};
    sfVector2f move = {d_pos.x / enemy->player_dist * speed,
        d_pos.y / enemy->player_dist * speed};
    enemy->pos.x += move.x;
    enemy->pos.y += move.y;
    enemy->bbox = (sfFloatRect) {enemy->pos.x - 32, enemy->pos.y - 32,
        64, 64};
}

static void move_enemy(instance_t *instance, enemy_t *enemy, float dtime,
    struct queue *queue)
{
    player_t *player = &instance->player;
    if (enemy->player_dist < 64) {
        player->health.current -= (1 / player->stats[STAT_DEFENSE]) * dtime;
        player->time[TIME_REGEN] = 0;
        return;
    }
    for (int i = 0; i < queue->last; ++i)
        if (sfFloatRect_intersects(&enemy->bbox,&((enemy_t *)
            queue->queue[i])->bbox, NULL)) return;
    if (enemy->player_dist > 248) return;
    update_enemy_pos(enemy, dtime, player);
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
        float dtime = sfTime_asSeconds(sfClock_getElapsedTime(
            enemy->sprite_clock));
        move_enemy(instance, enemy, dtime, &queue);
    }
    instance->enemy_heap->value = &enemy_pos;
    instance->enemy_behind = 0;
    for (int i = 0; i < ENEMY_COUNT; ++i) {
        sfClock_restart(instance->enemies[i].sprite_clock);
        update_enemy_render_stage(instance, &instance->enemies[i]);
    }
}
