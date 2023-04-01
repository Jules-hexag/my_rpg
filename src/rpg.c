/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** rpg
*/

#include <unistd.h>
#include <stdlib.h>
#include "rpg.h"

/* ajouter les const comme il faut */

int rpg(int const argc, char const *const *const argv)
{
    char *filepath = NULL;

    (void) argc;
    (void) argv;

    sfRenderWindow *window = init_window();
    instance_t *instance = create_instance(window);

    game_loop(instance);

    free(instance);
    sfRenderWindow_destroy(window);

    return 0;
}
