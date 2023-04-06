/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** rpg
*/

#ifndef RPG_H_
    #define RPG_H_
    #include "menu.h"
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Types.h>
    #include <SFML/System/Vector2.h>

    #define FILE_MAP_WIDTH 80
    #define FILE_MAP_HEIGHT 80

    #define IMG_SIZE 10

    #define RPG_SUCCESS 0
    #define RPG_FAILURE 84

    #include <stdbool.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/View.h>
    #include <SFML/System/Clock.h>

typedef struct map_s {
    int *const *map1;
    sfSprite *background;
} map_t;

enum tile_type {
    TILE_GRASS,
    TILE_TREE,
    TILE_WATER,
};

enum player_state {
    STRAIGHT,
    DRUGGED,
};

typedef struct {
    sfRenderWindow *window;
    sfVector2u size;
} window_t;


typedef struct {
    int current;
    int max;
} barector;

typedef struct {
    sfClock *npc_clock;
    sfSprite *sprite;
    sfVector2f pos;
    // void (*func)(struct instance_s *);
} npc_t;

typedef struct {
    sfClock *entity_clock;
    sfSprite *sprite;
    sfVector2f pos;
    barector health;
} ennemy_t;

typedef struct {
    sfClock *player_clock;
    sfSprite *sprite;
    sfVector2f pos;
    enum player_state state;
    barector health;
    barector mana;
} player_t;

typedef struct {
    int nb_mana;
    int garbage_item;
    int item[9];
} inventory_t;

typedef struct {
    sfSprite *background;
    sfText *text_sprite;
    char *Title;
    char *Text;
    sfClock *clock;
} speeches_t;

typedef struct instance_s{
    window_t *window_stats;
    map_t *map;
    all_menus *all_menus;
    player_t *player_stats;
    ennemy_t ennemies[10];
    npc_t npc[2];
    speeches_t speeches;
} instance_t;

/* sort all this in different appropriate files */

int rpg(int argc, char const *const *argv);

bool check_exec_errors(int argc, char const *const *argv,
    char const *const *envp);

void game_loop(instance_t *instance);

void map_display(instance_t *instances);

void resize_event(sfEvent event, window_t *window_stats);

sfRenderWindow *init_window(void);

map_t *create_map(window_t *window_stats);

void game_events_management(window_t *window_stats);

sfSprite *create_sprite(char *filepath);

void free_arrays(int **map);

void free_tileset(sfSprite **tileset);

int generate_int_tab_map(const char *const filepath, map_t *map_s);

int my_strncmp(char const *s1, char const *s2, int n);

instance_t *create_instances(void);

/*  MENU FUNCTION (header call recursion)*/

menu generate_start_menu(window_t *window_stats);
int start_menu_loop(window_t *window_stats, menu *start_menu);
int start_events_management(window_t *window_stats, menu *start_menu);
void mouse_moved_evt(window_t *window_stats, menu *start_menu);
void mouse_clicked_evt(window_t *window_stats, menu *start_instances);
int mouse_released_evt(window_t *window_stats, menu *start_menu);

#endif /* !RPG_H_ */
