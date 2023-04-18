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

void update_times(player_t *player, float dtime)
{
    player->time[TIME_REGEN] += dtime;
    if (player->time[TIME_REGEN] > player->stats[STAT_REGEN_TIME]
        && player->health.current < player->health.max)
        player->health.current += player->stats[STAT_REGEN] * dtime;

    player->time[MANA_TIME] -= dtime / 60;
    if (player->time[MANA_TIME] < 0)
        player->time[MANA_TIME] = 0;
    player->mana.current = player->time[MANA_TIME];
}

static void move_player(player_t *player, sfVector2i map_size,
    float dtime)
{
    sfVector2f *player_pos = &player->map_pos;
    float speed = player->stats[STAT_SPEED] * dtime;
    sfVector2f d_pos = {0, 0};
    if (sfKeyboard_isKeyPressed(sfKeyQ) && player_pos->x - 32 > 0)
        d_pos.x--;
    if (sfKeyboard_isKeyPressed(sfKeyD) && player_pos->x + 32 < map_size.x * 64)
        d_pos.x++;
    if (sfKeyboard_isKeyPressed(sfKeyZ) && player_pos->y - 32 > 0)
        d_pos.y--;
    if (sfKeyboard_isKeyPressed(sfKeyS) && player_pos->y + 32 < map_size.y * 64)
        d_pos.y++;
    float dist = sqrtf(powf(d_pos.x, 2) + powf(d_pos.y, 2));
    if (dist == 0)
        return;
    sfVector2f move = {d_pos.x / dist * speed, d_pos.y / dist * speed};
    player_pos->x += move.x;
    player_pos->y += move.y;
    player->bbox = (sfFloatRect) {player_pos->x - 32, player_pos->y - 32, 64, 64};
}

void update_player(instance_t *instance)
{
    player_t *player = &instance->player;
    float dtime = sfTime_asSeconds(sfClock_getElapsedTime(player->clock));
    sfClock_restart(player->clock);
    if (!sfRenderWindow_hasFocus(instance->window_params.window))
        return;
    update_times(player, dtime);
    if (player->time[TIME_REGEN] > player->stats[STAT_REGEN_TIME]
        && player->health.current < player->health.max) {
        player->health.current += player->stats[STAT_REGEN] * dtime;
    }
    move_player(&instance->player, instance->map->size, dtime);
    sfView *view =
        (sfView *) sfRenderWindow_getView(instance->window_params.window);
    sfView_setCenter(view,instance->player.map_pos);
    sfRenderWindow_setView(instance->window_params.window, view);
    sfSprite *sprite = instance->player.sprite;
    sfSprite_setPosition(sprite, instance->player.map_pos);
}
