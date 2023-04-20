/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** render_top_text.c
*/

#include "rpg.h"

void render_top_text(instance_t *instance)
{
    sfRenderWindow *window = instance->window_params.window;
    sfRenderWindow_drawText(window, instance->text.text_sprite, NULL);
}
