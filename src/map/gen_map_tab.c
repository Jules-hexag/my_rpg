/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_map
*/

#include "rpg.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int retrieve_lines(char *str_map, int **map)
{
    if (!map) return RPG_FAILURE;
    size_t width = 0;
    size_t height = 0;
    for (size_t str_it = 0; str_it < (FILE_WIDTH + 1) * FILE_HEIGHT;
        str_it++, width++) {
        if (str_map[str_it] == '\n') {
            height++;
            width = 0;
            continue;
        }
        str_map[str_it] == '0' ? map[height][width] = 0 : 0;
        str_map[str_it] == '1' ? map[height][width] = 1 : 0;
        str_map[str_it] == '2' ? map[height][width] = 2 : 0;
    }
    return RPG_SUCCESS;
}

int **gen_map_tab(char *filepath)
{
    int size = (FILE_WIDTH + 1) * FILE_HEIGHT + 1;
    char *str_map = malloc(size);
    int fd = open(filepath, O_RDONLY);
    if (!str_map) return NULL;
    if (read(fd, str_map, size) == -1) return NULL;
    str_map[size - 1] = '\0';
    int **map = malloc(sizeof(int *) * (FILE_HEIGHT + 1));
    if (!map) return NULL;
    map[80] = NULL;
    for (int i = 0; i < FILE_HEIGHT; i++) {
        map[i] = malloc(sizeof(int) * FILE_WIDTH + 1);
        if (!map[i]) return NULL;
    }
    if (retrieve_lines(str_map, map)) return NULL;
    close(fd);
    return map;
}
