/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_tutorial
*/

#include "rpg.h"

void update_tutorial(instance_t *instance)
{
    update_top_text(instance);
    update_player(instance);
    update_enemy(instance);
    update_bars(instance);
}
