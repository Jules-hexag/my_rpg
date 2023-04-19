/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_player
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/View.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Keyboard.h>
#include <math.h>
#include "rpg.h"

void update_sprite(player_t *player)
{
    enum SPRITE_DIR dir = (((int) (player->stats[STAT_ANGLE] * 180 / M_PI)
        + 360) % 360) / 45;
    if (!sfKeyboard_isKeyPressed(sfKeyD) && dir == 0)
        dir = 2;
    sfSprite_setTextureRect(player->sprite,
        (sfIntRect) {player->sprite_nb * 16 * player->walk, dir * 32, 16, 32});
}

void update_times(player_t *player)
{
    float dtime = sfTime_asSeconds(sfClock_getElapsedTime(player->clock));
    player->time[TIME_REGEN] += dtime;
    if (player->time[TIME_REGEN] > player->stats[STAT_REGEN_TIME]
        && player->health.current < player->health.max)
        player->health.current += player->stats[STAT_REGEN] * dtime;
    player->time[TIME_MANA] -= dtime / 60;
    if (player->time[TIME_MANA] < 0)
        player->time[TIME_MANA] = 0;
    player->mana.current = player->time[TIME_MANA];
    player->time[TIME_ATTACK] -= dtime;
    if (player->time[TIME_ATTACK] < 0)
        player->time[TIME_ATTACK] = 0;
    player->time[TIME_SPRITE] += dtime;
    if (player->time[TIME_SPRITE] > 0.1f) {
        player->time[TIME_SPRITE] = 0;
        player->sprite_nb = (player->sprite_nb + 1) % 6;
    }
}

static void get_keys(sfVector2f *d_pos, sfVector2i map_size, sfVector2f p_pos,
    bool *walk)
{
    *walk = false;
    if (sfKeyboard_isKeyPressed(sfKeyQ) && p_pos.x > 32)
        d_pos->x--;
    if (sfKeyboard_isKeyPressed(sfKeyD) && p_pos.x < map_size.x * 64 - 32)
        d_pos->x++;
    if (sfKeyboard_isKeyPressed(sfKeyZ) && p_pos.y > 32)
        d_pos->y--;
    if (sfKeyboard_isKeyPressed(sfKeyS) && p_pos.y < map_size.y * 64 - 32)
        d_pos->y++;
    if (d_pos->y != 0 || d_pos->x != 0)
        *walk = true;
}

static void move_player(player_t *player, sfVector2i map_size)
{
    sfVector2f *player_pos = &player->map_pos;
    float dtime = sfTime_asSeconds(sfClock_getElapsedTime(player->clock));
    float speed = player->stats[STAT_SPEED] * dtime;
    sfVector2f d_pos = {0, 0};
    get_keys(&d_pos, map_size, *player_pos, &player->walk);
    player->stats[STAT_ANGLE] = atan2f(d_pos.y, d_pos.x);
    float dist = sqrtf(powf(d_pos.x, 2) + powf(d_pos.y, 2));
    if (dist == 0)
        return;
    sfVector2f move = {d_pos.x / dist * speed, d_pos.y / dist * speed};
    player_pos->x += move.x;
    player_pos->y += move.y;
    player->bbox = (sfFloatRect) {player_pos->x - 32, player_pos->y - 32,
        64, 64};
}

void update_player(instance_t *instance)
{
    player_t *player = &instance->player;
    float dtime = sfTime_asSeconds(sfClock_getElapsedTime(player->clock));
    update_times(player);
    if (player->time[TIME_REGEN] > player->stats[STAT_REGEN_TIME]
        && player->health.current < player->health.max)
        player->health.current += player->stats[STAT_REGEN] * dtime;

    move_player(&instance->player, instance->map->size);
    attack_zombies(instance);
    update_sprite(&instance->player);
    sfView *view =
        (sfView *) sfRenderWindow_getView(instance->window_params.window);
    sfView_setCenter(view,instance->player.map_pos);
    sfRenderWindow_setView(instance->window_params.window, view);
    sfSprite *sprite = instance->player.sprite;
    sfSprite_setPosition(sprite, instance->player.map_pos);
    sfClock_restart(player->clock);
}
