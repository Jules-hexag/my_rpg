/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** check_exec_errors
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* mettre les const comme il faut */
static bool check_display_mode(char const *const *const envp)
{
    int str_iterator = 0;

    while (envp[str_iterator] != NULL) {
        if (strncmp(envp[str_iterator], "DISPLAY=", 8) == 0)
            return false;
        str_iterator++;
    }

    return true;
}

/* ajouter les const comme il faut */
bool check_exec_errors(int const argc, char const *const *const argv,
    char const *const *const envp)
{
    (void) argc;
    (void) argv;

    if (check_display_mode(envp))
        return true;

    return false;
}
