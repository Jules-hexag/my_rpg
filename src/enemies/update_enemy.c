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

static void update_layer(instance_t *instance, enemy_t *enemy)
{
    if (enemy->is_dead)
        return;
    int alpha = 255 * (enemy->health.current / enemy->health.max);
    sfColor color = sfColor_fromRGBA(255, alpha, alpha, 255);
    sfSprite_setColor(enemy->sprite, color);
    bh_append(instance->enemy_heap, enemy);
    if (enemy->pos.y < instance->player.map_pos.y)
        instance->enemy_behind++;
}

static void update_etp(instance_t *instance, enemy_t *enemy)
{
    if (enemy->is_dead)
        return;
    enemy->etp[ETP_DIST] = sqrtf(powf(enemy->pos.x - instance->player.map_pos.x,
        2) + powf(enemy->pos.y - instance->player.map_pos.y, 2));
    enemy->etp[ETP_ANGLE] = atan2f(enemy->pos.y - instance->player.map_pos.y,
        enemy->pos.x - instance->player.map_pos.x);
    if (enemy->etp[ETP_DIST] <= ENEMY_VIEW)
        bh_append(instance->enemy_heap, enemy);
}

static void damage_player(instance_t *instance, enemy_t *enemy)
{
    float dtime = sfTime_asSeconds(sfClock_getElapsedTime(enemy->clock));
    player *player = &instance->player;

    if (enemy->etp[ETP_DIST] > 64 || enemy->is_dead)
        return;

    player->health.current -= (1 / player->stats[STAT_DEFENSE]) * dtime;
    player->clocks[TIME_REGEN] = 0;
}

static void update_enemy_pos(enemy_t *enemy, struct queue *queue)
{
    float dtime = sfTime_asSeconds(sfClock_getElapsedTime(enemy->clock));
    float dpos = ENEMY_SPEED * dtime;
    if (enemy->etp[ETP_DIST] < 64)
        return;
    for (int i = 0; i < queue->last; ++i)
        if (sfFloatRect_intersects(&enemy->hitbox,
            &((enemy_t *) queue->queue[i])->hitbox, NULL))
            return;
    sfSprite_setPosition(enemy->sprite, enemy->pos);
    queue->queue[queue->last++] = enemy;
    enemy->pos.x -= cosf(enemy->etp[ETP_ANGLE]) * dpos;
    enemy->pos.y -= sinf(enemy->etp[ETP_ANGLE]) * dpos;
    enemy->hitbox = (sfFloatRect) {enemy->pos.x - 32, enemy->pos.y - 32,
        64, 64};
}

void update_enemy(instance_t *inst)
{
    struct queue queue = {0};
    inst->enemy_behind = 0;
    enemy_t *enemy;
    inst->enemy_heap->value = &enemy_value;
    for (unsigned int i = 0; i < inst->enemy_count[inst->current_map]; ++i) {
        if (inst->enemy[inst->current_map][i].health.current <= 0
            && !inst->enemy[inst->current_map][i].is_dead) {
            inst->enemy[inst->current_map][i].is_dead = true;
            inst->dead_enemies++;
        }
        update_etp(inst, &inst->enemy[inst->current_map][i]);
    }
    while ((enemy = bh_pop(inst->enemy_heap)))
        update_enemy_pos(enemy, &queue);
    inst->enemy_heap->value = &enemy_pos;
    for (unsigned int i = 0; i < inst->enemy_count[inst->current_map]; ++i) {
        damage_player(inst, &inst->enemy[inst->current_map][i]);
        sfClock_restart(inst->enemy[inst->current_map][i].clock);
        update_layer(inst, &inst->enemy[inst->current_map][i]);
    }
}
