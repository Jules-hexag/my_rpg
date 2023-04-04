/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** objects
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include "menu.h"
#include "rpg.h"

instance_t *create_instances(void)
{
    instance_t *instance = malloc(sizeof(instance_t));
    instance->window_stats = malloc(sizeof(window_t));
    instance->window_stats->window = init_window();
    instance->window_stats->size = (sfVector2u) {800, 800};
    instance->map = malloc(sizeof(map_t));
    instance->map->background = create_map(instance->window_stats);
    instance->all_menus = malloc(sizeof(all_menus));
    instance->all_menus->start_menu = generate_start_menu(
        instance->window_stats);

    return instance;
}
