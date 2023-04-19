/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** buttons_funcs
*/

#include "rpg.h"
#include <SFML/Graphics/Types.h>

void depause_game(instance_t *instance)
{
    instance->menu_state = IN_GAME;
}

void save_game(instance_t *instance)
{
    sfRenderWindow_close(instance->window_params.window);
}

void load_game(instance_t *instance)
{
    sfRenderWindow_close(instance->window_params.window);
}
