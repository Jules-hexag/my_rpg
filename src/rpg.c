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
    (void) argc;
    (void) argv;

    instance_t *instances = create_instances();
    if (start_menu_loop(instances->window_stats,
        &instances->all_menus->start_menu) == EXIT_PROGRAM) {
        return RPG_SUCCESS;
    }
    game_loop(instances);

    sfRenderWindow_destroy(instances->window_stats->window);
    free(instances);

    return RPG_SUCCESS;
}
// l.24 :
//  destroy window & free
//  + bien frire instances
