/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** render_tutorial
*/

#include "rpg.h"

void render_tutorial(instance_t *instance)
{
    render_tutorial_map(instance);
    render_player(instance);
    render_bars(instance);
}