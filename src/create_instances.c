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


/**
 * @brief Create an instances object containing all important data
 *
 * @return instance_t*
 */
instance_t *create_instances(void)
{
    instance_t *instances = malloc(sizeof(instance_t));
    instances->window_stats = malloc(sizeof(window_t));
    instances->window_stats->window = init_window();
    instances->window_stats->size = (sfVector2u) {800, 800};
    instances->map = create_map(instances->window_stats);
    instances->all_menus = malloc(sizeof(all_menus));
    instances->all_menus->start_menu = generate_start_menu(
        instances->window_stats);

    return instances;
}
