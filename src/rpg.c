/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** rpg
*/

#include <unistd.h>
#include "rpg.h"

/* ajouter les const comme il faut */

int rpg(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    char *filepath = NULL;
    frame_loop(filepath);
    return 0;
}
