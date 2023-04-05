/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** game_loop
*/

#include <stdlib.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderWindow.h>
#include "rpg.h"

void game_update(instance_t *objects)
{
    (void) objects;
}

void game_render(sfRenderWindow *window, instance_t *objects)
{
    sfRenderWindow_clear(window, sfBlack);
    map_display(objects);
    sfRenderWindow_display(window);
}

void game_loop(instance_t *instance)
{
    (void) instance;
    while (sfRenderWindow_isOpen(instance->window_stats->window)) {
        game_events_management(instance->window_stats);
        game_update(instance);
        game_render(instance->window_stats->window, instance);
    }
}
