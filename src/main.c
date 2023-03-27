/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main
*/

#include "rpg.h"

/* Ajouter les const comme il faut */

int main(int const argc, char **argv, char **env)
{
    if (input_errors(argc, argv, env)) {
        return 84;
    }
    return rpg(argc, (char **) argv[1]);
}
