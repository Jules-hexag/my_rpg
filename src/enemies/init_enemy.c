/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_enemy.c
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/RectangleShape.h>
#include "binary_heap.h"
#include "rpg.h"

enemy_t create_enemy(sfVector2f pos, instance_t *instance)
{
    enemy_t enemy;
    pos = (sfVector2f) {pos.x * 64, pos.y * 64};
    enemy.pos = pos;
    enemy.bbox = (sfFloatRect) {pos.x - 32, pos.y - 32, 64, 64};
    enemy.health = (barector) {100, 100};
    enemy.sprite_clock = sfClock_create();
    enemy.sprite = sfSprite_create();
    sfSprite_setTexture(enemy.sprite, instance->texture[TEXTURE_ENEMY], sfTrue);
    sfSprite_setPosition(enemy.sprite, pos);
    sfSprite_setScale(enemy.sprite, (sfVector2f) {4, 4});
    sfSprite_setOrigin(enemy.sprite, (sfVector2f) {8, 24});
    return enemy;
}

int enemy_value(void *enemy)
{
    return ((enemy_t *) enemy)->player_dist;
}

int enemy_pos(void *enemy)
{
    return ((enemy_t *) enemy)->pos.y;
}

void init_enemies(instance_t *instance)
{
    instance->enemies[0] = create_enemy((sfVector2f) {1, 5}, instance);
    instance->enemies[1] = create_enemy((sfVector2f) {4, 5}, instance);
    instance->enemies[2] = create_enemy((sfVector2f) {5, 2}, instance);
    instance->enemy_heap = bh_create(ENEMY_COUNT, BH_MIN, &enemy_value);
}
