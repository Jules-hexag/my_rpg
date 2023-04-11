/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_bars
*/

#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/System/Vector2.h>
#include "rpg.h"

static sfSprite *create_health_bar_sprite(instance_t *instance,
    int gauge_number)
{
    sfSprite *gauge = sfSprite_create();
    sfIntRect rect = gauge_number ? (sfIntRect) {8, 0, 8, 8} :
        (sfIntRect){0, 0, 8, 8};
    sfTexture *texture = sfTexture_createFromFile("res/bars.png", &rect);

    sfSprite_setTexture(gauge, texture, sfTrue);
    sfSprite_setPosition(gauge, (sfVector2f) {0, 0});

    int bar_max = instance->player.health.max;
    int bar_current = instance->player.health.current;
    gauge_number ? sfSprite_setScale(gauge, (sfVector2f) {bar_current, 1}) :
        sfSprite_setScale(gauge, (sfVector2f) {bar_max, 1});

    return gauge;
}

static sfSprite *create_mana_bar_sprite(instance_t *instance, int gauge_number)
{
    sfSprite *gauge = sfSprite_create();
    sfIntRect rect = gauge_number ? (sfIntRect) {8, 8, 8, 8} :
        (sfIntRect){0, 8, 8, 8};
    sfTexture *texture = sfTexture_createFromFile("res/bars.png", &rect);

    sfSprite_setTexture(gauge, texture, sfTrue);
    sfSprite_setPosition(gauge, (sfVector2f) {0, 10});

    int bar_max = instance->player.mana.max;
    int bar_current = instance->player.mana.current;
    gauge_number ? sfSprite_setScale(gauge, (sfVector2f) {bar_current, 1}) :
        sfSprite_setScale(gauge, (sfVector2f) {bar_max, 1});

    return gauge;
}

void init_bars(instance_t *instance)
{
    instance->bars[0].background = create_health_bar_sprite(instance, 0);
    instance->bars[0].current = create_health_bar_sprite(instance, 1);

    instance->bars[1].background = create_mana_bar_sprite(instance, 0);
    instance->bars[1].current = create_mana_bar_sprite(instance, 1);
}
