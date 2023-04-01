/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_map
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "rpg.h"
#include "map.h"

void iterator(size_t *col, size_t *line, size_t *str_it)
{
    if (*col == FILE_MAP_WIDTH - 1) {
        *col = 0;
        (*line)++;
        (*str_it)++;
    } else {
        (*col)++;
    }
    (*str_it)++;
}

static int retrieve_lines_from_buffer(char const *const str_map,
    int *const *const map)
{
    if (map == NULL || str_map == NULL)
        return RPG_FAILURE;
    for (size_t str_it = 0, line = 0, col = 0;
        str_it < (FILE_MAP_WIDTH + 1) * FILE_MAP_HEIGHT;
        iterator(&col, &line, &str_it))
        switch (str_map[str_it] - '0') {
            case TILE_GRASS:
                map[line][col] = TILE_GRASS;
                break;
            case TILE_TREE:
                map[line][col] = TILE_TREE;
                break;
            case TILE_WATER:
                map[line][col] = TILE_WATER;
                break;
            default:
                return RPG_FAILURE;
        }
    return RPG_SUCCESS;
}

static char const *read_file(char const *const filepath)
{
    size_t size = (FILE_MAP_WIDTH + 1) * FILE_MAP_HEIGHT + 1;
    char *file_map_buffer = malloc(sizeof(char [size]));
    int fd = open(filepath, O_RDONLY);

    if (file_map_buffer == NULL)
        return NULL;

    if (read(fd, file_map_buffer, size) == -1) {
        free(file_map_buffer);
        close(fd);
        return NULL;
    }
    close(fd);

    file_map_buffer[size - 1] = '\0';
    return file_map_buffer;
}

static int *const *init_map_tab(void)
{
    int **map = NULL;
    int *map_buffer = malloc(sizeof(int [FILE_MAP_WIDTH * FILE_MAP_HEIGHT]));
    if (map_buffer == NULL)
        return NULL;

    map = malloc(sizeof(int *[FILE_MAP_HEIGHT]));
    if (map == NULL) {
        free(map_buffer);
        return NULL;
    }

    for (int i = 0; i < FILE_MAP_HEIGHT; i++)
        map[i] = &map_buffer[i * FILE_MAP_WIDTH];

    return (int *const *) map;
}

int const *const *gen_map_tab(const char *const filepath)
{
    char const *file_map_buffer = read_file(filepath);
    if (file_map_buffer == NULL)
        return NULL;

    int *const *map = init_map_tab();
    if (map == NULL || *map == NULL) {
        free((void *) file_map_buffer);
        return NULL;
    }

    if (retrieve_lines_from_buffer(file_map_buffer, map)) return NULL;

    return (int const *const *)map;
}
