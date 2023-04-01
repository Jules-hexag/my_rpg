/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** rpg
*/

#ifndef RPG_H_
    #define RPG_H_

    #define WIN_WIDTH 800
    #define WIN_HEIGHT 800

    #define FILE_MAP_WIDTH 80
    #define FILE_MAP_HEIGHT 80

    #define IMG_SIZE 10

    #define RPG_SUCCESS 0
    #define RPG_FAILURE 84

    #include <stdbool.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/View.h>

typedef struct map_s {
    int **map1;
    sfSprite *background;
} map_t;

typedef struct instance_s {
    map_t *map;
    sfRenderWindow *window;
    sfVector2f player_pos;
} instance_t;

/* sort all this in different appropriate files */

int rpg(int argc, char const *const *argv);

bool check_exec_errors(int argc, char const *const *argv,
    char const *const *envp);

void game_loop(instance_t *instance);

sfRenderWindow *init_window(void);

sfSprite *create_map(sfRenderWindow *window);

void events_management(sfRenderWindow *window);

sfSprite *create_sprite(char *filepath);

void free_arrays(int **map);

void free_tileset(sfSprite **tileset);

const int *const * gen_map_tab(const char *const filepath);



instance_t *create_instance(sfRenderWindow *window);

#endif /* !RPG_H_ */
