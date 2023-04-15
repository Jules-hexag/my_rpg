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
    sfSprite_setPosition(p_sprite, (sfVector2f) {player->map_pos.x,
        player->map_pos.y});
    sfSprite_setOrigin(p_sprite, (sfVector2f) {8, 28});
    sfSprite_setScale(p_sprite, (sfVector2f) {4, 4});
    player->sprite = p_sprite;
}

player_t init_player(void)
{
    player_t player = {0};
    player.map_pos = (sfVector2f) {48, 48};
    player.health = (barector) {6, 8};
    player.mana = (barector) {6, 8};
    player.state = STRAIGHT;
    player.update_clock = sfClock_create();
    player.sprite_clock = sfClock_create();
    create_player_sprite(&player);
    return player;
}
