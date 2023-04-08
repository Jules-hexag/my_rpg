/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** rpg
*/

#pragma once

#include "menu.h"
#include <SFML/Graphics/Types.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector2.h>
#include <stdint.h>

#define FILE_MAP_WIDTH 80
#define FILE_MAP_HEIGHT 80

#define IMG_SIZE 10

#define RPG_SUCCESS 0
#define RPG_FAILURE 84

#include <stdbool.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Clock.h>

typedef struct {
    sfRenderStates states;
    sfTexture *tileset;
    sfVertexArray *array;
} tilemap_t;

typedef struct map_s {
    sfVector2i size;
    tilemap_t *background;
    uint8_t **map;
} map_t;

enum tile_type {
    TILE_ALPHA,
    TILE_GRASS,
    TILE_GRASS_SAND,
    TILE_SAND,
    TILE_THING,
    TILE_SAND_WATER,
    TILE_WATER,

    TILE_COUNTER
};

enum player_state {
    STRAIGHT,
    DRUGGED,
};

typedef struct {
    sfRenderWindow *window;
    sfVector2u size;
} window_params_t;


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

enum game_state {
    IN_GAME,
    IN_START_MENU,
    IN_PAUSE_MENU,
    IN_INVENTORY,
    IN_SPEECH,
};

enum menus {
    START_MENU,
    INVENTORY,
    PAUSE,

    MENU_COUNT
};

typedef struct instance_s{
    enum game_state menu_state;
    map_t map[1];
    window_params_t window_params;
    npc_t npc[2];
    ennemy_t ennemies[10];
    menu_t menus[MENU_COUNT];
    player_t player;
    speeches_t speeches;
} instance_t;

/* sort all this in different appropriate files */

int rpg(int argc, char const *const *argv);

bool is_exec_errors(int argc, char const *const *argv,
    char const *const *envp);

void rpg_loop(instance_t *instance);

void render_map(instance_t *instances);

void resize_event(sfEvent event, window_params_t *window_params);

sfRenderWindow *init_window(void);
map_t init_map(void);

void game_events_management(window_params_t *window_params);

sfSprite *create_sprite(char *filepath);

void free_arrays(int **map);

void free_tileset(sfSprite **tileset);

int generate_int_tab_map(const char *const filepath, map_t *map_s);

int my_strncmp(char const *s1, char const *s2, int n);

instance_t init_instance(void);

/*  MENU FUNCTION (header call recursion)*/


int start_menu_loop(window_params_t *window_stats, menu_t *start_menu);
int start_events_management(window_params_t *window_stats, menu_t *start_menu);
void mouse_moved_evt(window_params_t *window_stats, menu_t *start_menu);
void mouse_clicked_evt(window_params_t *window_stats, menu_t *start_instances);
void mouse_released_evt(window_params_t *window_stats, menu_t *start_menu);

instance_t init_instance(void);
menu_t init_start_menu(window_params_t *window_params);

void render_game(instance_t *instance);
void render_start_menu(instance_t *instance);

void update_game(instance_t *instance);
void update_start_menu(instance_t *instance);

void manage_game_events(instance_t *instance, sfEvent event);
void manage_start_menu_events(instance_t *instance, sfEvent event);

void destroy_map(map_t *map);
