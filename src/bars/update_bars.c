/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_bars
*/

#include "rpg.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

static void update_health_bars_scale(instance_t *instance, sfSprite *health_bg,
    sfSprite *health_current)
{
    sfSprite_setScale(health_bg, (sfVector2f) {instance->player.health.max *
        4, 4});
    sfSprite_setScale(health_current, (sfVector2f) {
        instance->player.health.current * 4, 4});
}

static void update_mana_bars_scale(instance_t *instance, sfSprite *mana_bg,
    sfSprite *mana_current)
{
    sfSprite_setScale(mana_bg, (sfVector2f) {instance->player.mana.max * 8, 4});
    sfSprite_setScale(mana_current, (sfVector2f) {
        instance->player.mana.current * 8, 4});
}

static void update_health_bars_pos(instance_t *instance, sfView const *view,
    sfSprite *health_bg, sfSprite *health_current)
{
    sfRenderWindow *window = instance->window_params.window;
    sfSprite_setPosition(health_bg, sfRenderWindow_mapPixelToCoords(window,
        (sfVector2i) {10, 10}, view));
    sfSprite_setPosition(health_current, sfRenderWindow_mapPixelToCoords(window,
        (sfVector2i) {10, 10}, view));
}

static void update_mana_bars_pos(instance_t *instance, sfView const *view,
    sfSprite *mana_bg, sfSprite *mana_current)
{
    sfRenderWindow *window = instance->window_params.window;
    sfSprite_setPosition(mana_bg,
        sfRenderWindow_mapPixelToCoords(window,(sfVector2i) {10, 58}, view));
    sfSprite_setPosition(mana_current,
        sfRenderWindow_mapPixelToCoords(window,(sfVector2i) {10, 58}, view));
}

void update_bars(instance_t *instance)
{
    sfRenderWindow *window = instance->window_params.window;
    sfView const *view = sfRenderWindow_getView(window);
    player *player = &instance->player;
    sfSprite *health_bg = instance->bars[B_HEALTH].background;
    sfSprite *health_current = instance->bars[B_HEALTH].current;
    sfSprite *mana_bg = instance->bars[B_MANA].background;
    sfSprite *mana_current = instance->bars[B_MANA].current;
    callback_bars(instance);
    if (player->health.current < 0)
        player->mana.current = 0;
    if (player->health.current > player->health.max)
        player->health.current = player->health.max;
    if (player->mana.current < 0)
        player->mana.current = 0;
    update_health_bars_pos(instance, view, health_bg, health_current);
    update_mana_bars_pos(instance, view, mana_bg, mana_current);
    update_mana_bars_scale(instance, mana_bg, mana_current);
    update_health_bars_scale(instance, health_bg, health_current);
}
