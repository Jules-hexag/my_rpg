/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_player
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Vector2.h>
#include "rpg.h"

void update_player(instance_t *instance)
{
    sfView *view = sfRenderWindow_getView(instance->window_params.window);
    sfView_setCenter(view,instance->player.pos);
    sfRenderWindow_setView(instance->window_params.window, view);
    sfSprite *sprite = instance->player.sprite;
    sfSprite_setPosition(sprite, instance->player.pos);
}
