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
#include "rpg.h"

static void move_player(sfVector2f *player_pos, sfVector2i map_size,
    int dtime)
{
    float speed = 4 * dtime / (1000.f / 60.f);
    if (sfKeyboard_isKeyPressed(sfKeyQ) && player_pos->x - 24 > 0)
        player_pos->x -= speed;
    if (sfKeyboard_isKeyPressed(sfKeyD) && player_pos->x + 24 < map_size.x * 64)
        player_pos->x += speed;
    if (sfKeyboard_isKeyPressed(sfKeyZ) && player_pos->y - 8 > 0)
        player_pos->y -= speed;
    if (sfKeyboard_isKeyPressed(sfKeyS) && player_pos->y + 8 < map_size.y * 64)
        player_pos->y += speed;
}

void update_player(instance_t *instance)
{
    int dtime = sfTime_asMilliseconds(sfClock_getElapsedTime(
        instance->player.update_clock));
    sfClock_restart(instance->player.update_clock);
    move_player(&instance->player.map_pos, instance->map->size, dtime);
    sfView *view =
        (sfView *) sfRenderWindow_getView(instance->window_params.window);
    sfView_setCenter(view,instance->player.map_pos);
    sfRenderWindow_setView(instance->window_params.window, view);
    sfSprite *sprite = instance->player.sprite;
    sfSprite_setPosition(sprite, instance->player.map_pos);
}
