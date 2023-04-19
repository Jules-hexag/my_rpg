/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_game.c
*/

#include <stdio.h>
#include "rpg.h"

void init_game(instance_t *instance)
{
    instance->player = init_player(instance);
    init_enemies(instance);
}

void load_game(instance_t *instance)
{
    FILE *save = fopen("save/save.txt", "r");
    fread(instance, sizeof(instance_t), 1, save);
    fclose(save);
}
