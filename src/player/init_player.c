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

static void create_player_sprite(player_t *player)
{
    sfSprite *p_sprite = sfSprite_create();
    sfIntRect rect = {0, 0, 16, 32};
    sfTexture *texture = sfTexture_createFromFile("res/player.png", &rect);
    sfSprite_setTexture(p_sprite, texture, sfTrue);
    sfSprite_setPosition(p_sprite, (sfVector2f) {player->pos.x, player->pos.y});
    player->sprite = p_sprite;
}

player_t init_player(void)
{
    player_t player = {0};
    player.pos = (sfVector2f) {48, 48};
    player.mana = (barector) {30, 30};
    player.health = (barector) {30, 30};
    player.state = STRAIGHT;
    player.player_clock = sfClock_create();
    create_player_sprite(&player);
    return player;
}
