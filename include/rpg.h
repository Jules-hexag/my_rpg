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

    #define FILE_WIDTH 80
    #define FILE_HEIGHT 80

    #define IMG_SIZE 10

    #define RPG_SUCCESS 0
    #define RPG_FAILURE 84

    #include <stdbool.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/View.h>

/* sort all this in different appropriate files */

int rpg(int argc, char **argv);

bool input_errors(int argc, char **argv, char **env);

void frame_loop(char *filepath);

sfRenderWindow *init_window(void);

sfSprite *create_map(sfRenderWindow *window);

void events_management(sfRenderWindow *window);

sfSprite *create_sprite(char *filepath);

void free_arrays(int **map);

void free_tileset(sfSprite **tileset);

int **gen_map_tab(char *filepath);

typedef struct object_s {
    sfSprite    *background;
} objects_t;

objects_t *create_objects(sfRenderWindow *window);

typedef struct maps_s {
    int **map1;
} maps_t;

#endif /* !RPG_H_ */
