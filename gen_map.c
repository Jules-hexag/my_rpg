/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** gen_map.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "rpg.h"

int main(int ac, char **av)
{
    int x = atoi(av[1]);
    int y = atoi(av[2]);
    map_t *map = malloc(sizeof(map_t));
    map->size = (sfVector2i) {
        .x = x, .y = y
    };
    map->map = NULL;
    map->sprite = NULL;
    map->tileset = NULL;
    write(1, map, sizeof(map_t));
    char *tab = malloc(sizeof(char [(x + 1) * y]));
    char *line = malloc(sizeof(char [x + 1]));
    size_t size = x;
    for (int i = 0; i < y; i++) {
        getline(&line, &size, stdin);
        tab[(i + 1) * (x + 1)] = 0;
        for (int j = 0; j < x; j++)
            tab[i * (x + 1) + j] = line[j] - 'a';
    } write(1, tab, (x + 1) * y);
    return 0;
}
