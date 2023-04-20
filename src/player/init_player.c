/*
** EPITECH PROJECT, 2023
** gen_map
** File description:
** init_player.c
*/

#include "rpg.h"
#include <SFML/Config.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>

void create_player_sprite(instance_t *instance, player *player)
{
    sfSprite *p_sprite = sfSprite_create();
    sfIntRect rect = {0, 0, 16, 32};
    sfTexture *texture = instance->texture[TEXTURE_PLAYER];
    sfSprite_setTexture(p_sprite, texture, sfTrue);
    sfSprite_setTextureRect(p_sprite, rect);
    sfSprite_setPosition(p_sprite, (sfVector2f) {player->map_pos.x,
        player->map_pos.y});
    sfSprite_setOrigin(p_sprite, (sfVector2f) {8, 24});
    sfSprite_setScale(p_sprite, (sfVector2f) {4, 4});
    player->sprite = p_sprite;
}

void init_stats(player *player)
{
    player->stats[STAT_STRENGTH] = 50;
    player->stats[STAT_ATTACK_SPEED] = 0.5f;
    player->stats[STAT_DEFENSE] = 1;
    player->stats[STAT_SPEED] = 240;
    player->stats[STAT_REGEN] = 0.5f;
    player->stats[STAT_REGEN_TIME] = 3;
}

player init_player(instance_t *instance)
{
    player player = {0};
    player.map_pos = (sfVector2f) {48, 48};
    player.health = (barector) {8, 8};
    player.mana = (barector) {1, 1};
    player.state = STRAIGHT;
    player.hitbox = (sfFloatRect) {player.map_pos.x - 32, player.map_pos.y - 32,
        64, 64};
    player.clock = sfClock_create();
    player.clocks[TIME_REGEN] = 0;
    player.clocks[TIME_MANA] = player.mana.max;
    init_stats(&player);
    create_player_sprite(instance, &player);
    return player;
}
