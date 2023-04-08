/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main
*/

#include "rpg.h"

// Ajouter les const comme il faut
int main(int argc, char **argv, char **envp)
{
    if (is_exec_errors(argc, (char const *const *) argv,
        (char const *const *) envp)) {
        return 84;
    }

    return rpg(argc, (char const *const *) argv[1]);
}
