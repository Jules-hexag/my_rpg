/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** input_errors
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* mettre les const comme il faut */
static int display_mode(char **env)
{
    long unsigned int for_warning = 8;
    int env_vars = 0;
    while (env[env_vars] != NULL) {
        if (!strncmp(env[env_vars], "DISPLAY=", for_warning))
            return 0;
        env_vars++;
    }
    return 1;
}

/* ajouter les const comme il faut */
bool input_errors(int argc, char **argv, char **env)
{
    (void) argc;
    (void) argv;
    if (display_mode(env)) return true;
    return false;
}
