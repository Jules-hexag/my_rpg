/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** rpg
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "rpg.h"
#include "menu.h"

/**
 * @brief manage all the game: game loops and destroying instances
 *
 * @param argc
 * @param argv
 * @return int, the main function's return: RPG_SUCCESS / RPG_FAILURE
 */
int rpg(int const argc, char const *const *const argv)
{
    instance_t instance = init_instance();
    (void) argc;
    (void) argv;

    rpg_loop(&instance);

    sfRenderWindow_destroy(instance.window_params.window);

    destroy_instance(&instance);
    return RPG_SUCCESS;
}
// l.24 :
//  destroy window & free
//  + bien frire instances
