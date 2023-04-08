/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** objects
*/

#include <SFML/System/Vector2.h>
#include "rpg.h"

static window_params_t init_window_params(void)
{
    window_params_t window_params = {0};

    window_params.window = init_window();
    window_params.size = (sfVector2u) {800, 800};

    return window_params;
}

/**
 * @brief Create an instances object containing all important data
 *
 * @return instance_t*
 */
instance_t init_instance(void)
{
    instance_t instances = {0};

    instances.menu_state = IN_GAME;
    instances.window_params = init_window_params();
    instances.map[0] = init_map();
    instances.menus[START_MENU] = init_start_menu(&instances.window_params);

    return instances;
}
