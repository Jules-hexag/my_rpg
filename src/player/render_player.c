/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** render_player
*/

#include "rpg.h"
#include <SFML/Graphics/Types.h>

void render_player(instance_t *instances)
{
    sfRenderWindow *window = instances->window_params.window;
    sfSprite *p_sprite = instances->player.sprite;
    sfRenderWindow_drawSprite(window, p_sprite, NULL);
}
