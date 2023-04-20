/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_enemy.c
*/

#include <SFML/Graphics/Sprite.h>
#include "binary_heap.h"
#include "rpg.h"

sfVector2f const zombie_game[9] = {
    (sfVector2f) {10, 2},
    (sfVector2f) {11, 2},
    (sfVector2f) {12, 2},
    (sfVector2f) {10, 3},
    (sfVector2f) {11, 3},
    (sfVector2f) {12, 3},
    (sfVector2f) {10, 4},
    (sfVector2f) {11, 4},
    (sfVector2f) {12, 4}};

void create_enemy_sprite(instance_t *instance, enemy_t *enemy)
{
    enemy->clock = sfClock_create();
    enemy->sprite = sfSprite_create();
    sfSprite_setTexture(enemy->sprite,
        instance->texture[TEXTURE_ENEMY], sfTrue);
    sfSprite_setPosition(enemy->sprite, enemy->pos);
    sfSprite_setScale(enemy->sprite, (sfVector2f) {4, 4});
    sfSprite_setOrigin(enemy->sprite, (sfVector2f) {8, 24});
}

enemy_t create_enemy(sfVector2f pos, instance_t *instance)
{
    enemy_t enemy;
    pos = (sfVector2f) {pos.x * 64, pos.y * 64};
    enemy.pos = pos;
    enemy.hitbox = (sfFloatRect) {pos.x - 32, pos.y - 32, 64, 64};
    enemy.health = (barector) {100, 100};
    enemy.is_dead = false;
    create_enemy_sprite(instance, &enemy);
    return enemy;
}

int enemy_value(void *enemy)
{
    return ((enemy_t *)enemy)->etp[ETP_DIST];
}

int enemy_pos(void *enemy)
{
    return ((enemy_t *) enemy)->pos.y;
}

void init_enemies(instance_t *instance)
{
    instance->dead_enemies = 0;
    instance->enemy_behind = 0;
    instance->enemy_count[MAP_GAME] = 9;
    for (unsigned int i = 0; i < instance->enemy_count[MAP_GAME]; ++i)
        instance->enemy[MAP_GAME][i] = create_enemy(zombie_game[i], instance);
    instance->enemy_count[MAP_TUTORIAL] = 1;
    instance->enemy[MAP_TUTORIAL][0] = create_enemy((sfVector2f) {10, 2},
        instance);
    instance->enemy_heap = bh_create(MAX_ENEMIES, BH_MIN, &enemy_value);
}
