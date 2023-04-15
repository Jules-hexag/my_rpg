/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_bars
*/

#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include "rpg.h"

static bars_t create_health_bar_sprite(void)
{
    bars_t bar = {0};
    bar.background = sfSprite_create();
    sfIntRect bgrect = {0, 0, 8, 8};
    sfTexture *bgtexture = sfTexture_createFromFile("res/bars.png", &bgrect);
    sfSprite_setTexture(bar.background, bgtexture, sfTrue);
    bar.current = sfSprite_create();
    sfIntRect curect = {8, 0, 8, 8};
    sfTexture *cutexture = sfTexture_createFromFile("res/bars.png", &curect);
    sfSprite_setTexture(bar.current, cutexture, sfTrue);
    sfSprite_setScale(bar.current, (sfVector2f) {4, 4});

    return bar;
}

static bars_t create_mana_bar_sprite(void)
{
    bars_t bar = {0};
    bar.background = sfSprite_create();
    sfIntRect bgrect = {0, 8, 8, 8};
    sfTexture *bgtexture = sfTexture_createFromFile("res/bars.png", &bgrect);
    sfSprite_setTexture(bar.background, bgtexture, sfTrue);
    bar.current = sfSprite_create();
    sfIntRect curect = {8, 8, 8, 8};
    sfTexture *cutexture = sfTexture_createFromFile("res/bars.png", &curect);
    sfSprite_setTexture(bar.current, cutexture, sfTrue);
    sfSprite_setScale(bar.current, (sfVector2f) {4, 4});

    return bar;
}

void init_bars(instance_t *instance)
{
    instance->bars[B_HEALTH] = create_health_bar_sprite();

    instance->bars[B_MANA] = create_mana_bar_sprite();
}
