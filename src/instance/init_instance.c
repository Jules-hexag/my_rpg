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
    instance_t instance = {0};

    instance.menu_state = IN_START_MENU;
    instance.window_params = init_window_params();
    instance.map[MAP_GAME] = init_map("res/maps/map1");
    instance.map[MAP_TUTORIAL] = init_map("res/maps/map1");
    instance.menus[START_MENU] = init_start_menu(&instance.window_params);
    instance.player = init_player();
    init_bars(&instance);
    return instance;
}
