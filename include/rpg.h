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

#define PLAYER_WIDTH 16
#define PLAYER_HEIGHT 32

#define PLAYER_SPEED 4
#define ENEMY_SPEED 180

#define ENEMY_COUNT 3

#include <stdbool.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Clock.h>
#include "binary_heap.h"

struct queue {
    void *queue[ENEMY_COUNT];
    int last;
    int head;
};

enum texture_type {
    TEXTURE_PLAYER,
    TEXTURE_NPC,
    TEXTURE_TILESET,
    TEXTURE_ENEMY,
    TEXTURE_COUNT
};

enum button_state_e {
    NONE,
    HOVER,
    PRESSED,
};

enum start_menu_button {
    SMB_PLAY,
    SMB_RESUME,
    SMB_TUTORIAL,
    SMB_SETTINGS,
    SMB_QUIT,
    SMB_COUNT
};

enum settings_items {
    STT_WINDOWED,
    STT_FULLSCREEN,

    STT_BUTTON_COUNT,
};

typedef struct instance_s instance_t;

typedef struct {
    sfRectangleShape *button;
    sfFloatRect rect;
    sfVector2f origin;
    sfVector2f size;
    enum button_state_e button_state;
    sfText *text;
    void (*button_func) (instance_t *instance);
} menu_button_t;

typedef struct {
    menu_button_t *buttons;
} menu_t;

typedef struct map_s {
    sfVector2i size;
    sfTexture *tileset;
    sfVertexArray *array;
    sfRenderTexture *render;
    sfSprite *sprite;
    uint8_t **map;
} map_t;

enum map_e {
    MAP_TUTORIAL,
    MAP_GAME,

    MAP_COUNTER,
};

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
    sfView *view;
    sfVector2u size;
    sfSprite *menu_background;
} window_params_t;


typedef struct {
    float current;
    float max;
} barector;

typedef struct {
    sfClock *npc_clock;
    sfSprite *sprite;
    sfVector2f pos;
    // void (*func)(struct instance_s *);
} npc_t;

typedef struct {
    sfClock *sprite_clock;
    sfSprite *sprite;
    enum enemy_state {ALIVE, DEAD} state;
    float player_dist;
    sfVector2f pos;
    barector health;
    sfFloatRect bbox;
    sfRectangleShape *bbox_shape;
} enemy_t;

enum time_values {
    TIME_REGEN,
    MANA_TIME,

    TIME_COUNT
};

enum stats_value {
    STAT_DEFENSE,
    STAT_SPEED,
    STAT_STRENGTH,
    STAT_REGEN,
    STAT_REGEN_TIME,
    STAT_COUNT
};

typedef struct {
    sfClock *clock;
    sfSprite *sprite;
    float time[TIME_COUNT];
    float stats[STAT_COUNT];
    sfVector2f map_pos;
    sfFloatRect bbox;
    sfVector2f pos;
    enum player_state state;
    barector health;
    barector mana;
    int nb_mana_pills;
} player_t;

typedef struct {
    sfSprite *background;
    sfText *text_sprite;
    char *Title;
    char *Text;
} speeches_t;

enum game_state {
    IN_GAME,
    IN_START_MENU,
    IN_SETTINGS,
    IN_TUTORIAL,
    IN_PAUSE_MENU,
    IN_INVENTORY,
    IN_SPEECH,
};

enum bars {
    B_HEALTH,
    B_MANA,
    B_COUNT
};

typedef struct {
    sfSprite *background;
    sfSprite *current;
} bars_t;

enum menus {
    START_MENU,
    SETTINGS,
    INVENTORY,
    PAUSE,

    MENU_COUNT
};

struct instance_s {
    enum game_state menu_state;
    sfTexture *texture[TEXTURE_COUNT];
    int enemy_behind;
    map_t map[MAP_COUNTER];
    window_params_t window_params;
    npc_t npc[2];
    enemy_t enemies[ENEMY_COUNT];
    binary_heap *enemy_heap;
    menu_t menus[MENU_COUNT];
    player_t player;
    speeches_t speeches;
    bars_t bars[B_COUNT];
};

/* sort all this in different appropriate files */

int rpg(int argc, char const *const *argv);
void rpg_loop(instance_t *instance);

bool is_exec_errors(int argc, char const *const *argv,
    char const *const *envp);
int enemy_pos(void *enemy);
int enemy_value(void *enemy);
int my_strncmp(char const *s1, char const *s2, int n);
sfSprite *gen_sprite_shape(char *texture_path, sfVector2f pos);

/*  BUTTONS FUNCTIONS   (start menu)    */
void play_game(instance_t *instance);
void resume_game(instance_t *instance);
void tutorial(instance_t *instance);
void settings(instance_t *instance);
void quit_game(instance_t *instance);

/*  BUTTONS FUNCTIONS   (start menu)    */
void set_windowed(instance_t *instance);
void set_fullscreen(instance_t *instance);

map_t init_map(char *struct_path, instance_t *instance);
player_t init_player(instance_t *instance);
instance_t init_instance(void);
void gen_array_vertex(map_t *map);
sfRenderWindow *init_window(void);
menu_t init_start_menu(window_params_t *window_params);
menu_t init_settings(window_params_t *window_params);
void init_bars(instance_t *instance);
void init_enemies(instance_t *instance);
sfText *init_text(char *str_text);

void render_game_map(instance_t *instance);
void render_tutorial_map(instance_t *instance);
void render_game(instance_t *instance);
void render_start_menu(instance_t *instance);
void render_player(instance_t *instances);
void render_bars(instance_t *instances);
void render_front_enemy(instance_t *instance);
void render_back_enemy(instance_t *instance);
void render_tutorial(instance_t *instance);
void render_settings(instance_t *instance);

void update_instance(instance_t *instance);
void update_bars(instance_t *instance);
void update_player(instance_t *instance);
void update_game(instance_t *instance);
void update_start_menu(instance_t *instance);
void update_enemy(instance_t *instance);
void update_tutorial(instance_t *instance);
void update_settings(instance_t *instance);
void update_button_color(menu_button_t *button);

void manage_game_events(instance_t *instance, sfEvent event);
void manage_start_menu_events(instance_t *instance, sfEvent event);
void manage_tutorial_events(instance_t *instance, sfEvent event);
void manage_settings_events(instance_t *instance, sfEvent event);
void manage_key_pressed(instance_t *instance, sfEvent event);

void player_move(sfEvent event, instance_t *instance);

void destroy_map(map_t *map);
void destroy_instance(instance_t *instance);
