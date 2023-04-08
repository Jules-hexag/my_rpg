/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** is_exec_errors
*/

#include "rpg.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* mettre les const comme il faut */
static bool is_invalid_display_mode(char const *const *const envp)
{
    int str_iterator = 0;

    while (envp[str_iterator] != NULL) {
        if (my_strncmp(envp[str_iterator], "DISPLAY=", 8) == 0)
            return false;
        str_iterator++;
    }

    return true;
}

/* ajouter les const comme il faut */
bool is_exec_errors(int const argc, char const *const *const argv,
    char const *const *const envp)
{
    (void) argc;
    (void) argv;

    if (is_invalid_display_mode(envp))
        return true;

    return false;
}
