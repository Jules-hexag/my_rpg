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
}

static void get_keys(sfVector2f *d_pos, sfVector2i map_size, sfVector2f p_pos)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ) && p_pos.x > 32)
        d_pos->x--;
    if (sfKeyboard_isKeyPressed(sfKeyD) && p_pos.x < map_size.x * 64 - 32)
        d_pos->x++;
    if (sfKeyboard_isKeyPressed(sfKeyZ) && p_pos.y > 32)
        d_pos->y--;
    if (sfKeyboard_isKeyPressed(sfKeyS) && p_pos.y < map_size.y * 64 - 32)
        d_pos->y++;
}

static void move_player(player_t *player, sfVector2i map_size)
{
    sfVector2f *player_pos = &player->map_pos;
    float dtime = sfTime_asSeconds(sfClock_getElapsedTime(player->clock));
    float speed = player->stats[STAT_SPEED] * dtime;
    sfVector2f d_pos = {0, 0};
    get_keys(&d_pos, map_size, *player_pos);
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

void attack_zombies(instance_t *instance)
{
    player_t *player = &instance->player;
    if (player->time[TIME_ATTACK] > 0 || !sfKeyboard_isKeyPressed(sfKeySpace))
        return;
    for (int i = 0; i < ENEMY_COUNT; i++) {
        enemy_t *zombie = &instance->enemies[i];
        if (zombie->state == DEAD || zombie->etp[ETP_DIST] > 64)
            continue;
        zombie->health.current -= player->stats[STAT_STRENGTH];
    }
    player->time[TIME_ATTACK] = player->stats[STAT_ATTACK_SPEED];
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
    sfView *view =
        (sfView *) sfRenderWindow_getView(instance->window_params.window);
    sfView_setCenter(view,instance->player.map_pos);
    sfRenderWindow_setView(instance->window_params.window, view);
    sfSprite *sprite = instance->player.sprite;
    sfSprite_setPosition(sprite, instance->player.map_pos);
    sfClock_restart(player->clock);
}
