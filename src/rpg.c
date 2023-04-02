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
#include "start_menu.h"

int rpg(int const argc, char const *const *const argv)
{
    (void) argc;
    (void) argv;

    sfRenderWindow *window = init_window();

    if (start_menu_loop(window) == EXIT_PROGRAM) {
        // destroy window & free
        return 0;
    }
    // instance_t *instance = create_instances(window);
    // game_loop(instance);

    // free(instance);
    sfRenderWindow_destroy(window);

    return 0;
}
