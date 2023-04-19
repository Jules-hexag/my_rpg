/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** rpg
*/

#pragma once

#include <SFML/Audio.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector2.h>
#include <stdint.h>
#include <stdbool.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Clock.h>
#include "binary_heap.h"
#include "map.h"
#include "player.h"
#include "enemy.h"
#include "npc.h"
#include "menu.h"
#include "bars.h"
#include "window_params.h"


//CAN’T HAVE STRUCT TOO LARGE > 8000 bytes
#define MAX_ENEMIES 60
#define RPG_SUCCESS 0

#define ENEMY_SPEED 180
#define ENEMY_VIEW 500



struct queue {
    void *queue[MAX_ENEMIES];
    int last;
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

enum start_menu_button {
    SMB_PLAY,
    SMB_RESUME,
    SMB_TUTORIAL,
    SMB_SETTINGS,
    SMB_QUIT,
    SMB_BUTTON_COUNT
};

enum settings_items {
    STT_WINDOWED,
    STT_FULLSCREEN,
    STT_BACK,

    STT_BUTTON_COUNT,
};

enum pause_items {
    PMB_RESUME,
    PMB_SAVE,
    PMB_LOAD,
    PMB_SETTINGS,
    PMB_QUIT,

    PMB_BUTTON_COUNT,
};

typedef struct {
    sfSprite *background;
    sfText *text_sprite;
    char *Title;
    char *Text;
} speeches_t;


enum texture_type {
    TEXTURE_PLAYER,
    TEXTURE_NPC,
    TEXTURE_TILESET,
    TEXTURE_ENEMY,
    TEXTURE_COUNT
};

enum map_e {
    MAP_GAME,
    MAP_TUTORIAL,

    MAP_COUNTER,
};

enum game_state {
    IN_GAME,
    IN_START_MENU,
    IN_SETTINGS,
    IN_TUTORIAL,
    IN_PAUSE_MENU,
    IN_INVENTORY,
    IN_SPEECH,
};

enum menus {
    START_MENU,
    SETTINGS,
    PAUSE,
    INVENTORY,

    MENU_COUNT
};

enum bars {
    B_HEALTH,
    B_MANA,
    B_COUNT
};

enum SPRITE_DIR {
    SP_E,
    SP_SE,
    SP_S,
    SP_SW,
    SP_W,
    SP_NW,
    SP_N,
    SP_NE,
};

typedef struct instance_s {
    binary_heap *enemy_heap;
    sfTexture *texture[TEXTURE_COUNT];
    map_t map[MAP_COUNTER];
    enemy_t enemy[MAP_COUNTER][MAX_ENEMIES];
    npc npc[2];
    bars_t bars[B_COUNT];
    menu_t menus[MENU_COUNT];
    unsigned enemy_count[MAP_COUNTER];
    window_params window_params;
    unsigned dead_enemies;
    unsigned enemy_behind;
    enum game_state menu_state;
    enum map_e current_map;
    player player;
    volume_t volume;
} instance_t;


/* sort all this in different appropriate files */

int rpg(int argc, char const *const *argv);
void rpg_loop(instance_t *instance);

bool is_exec_errors(int argc, char const *const *argv,
    char const *const *envp);
int enemy_pos(void *enemy);
int enemy_value(void *enemy);
int my_strncmp(char const *s1, char const *s2, int n);
sfSprite *gen_sprite_shape(char *texture_path, sfVector2f pos);
void attack_zombies(instance_t *instance);
char *my_itoa(unsigned int nbr);
char *my_strcat(char *dest, const char *src);
void change_volume(instance_t *instance);

/*  BUTTONS FUNCTIONS   (start menu)    */
void play_game(void *instance);
void resume_game(void *instance);
void tutorial(void *instance);
void settings(void *instance);
void quit_game(void *instance);
/*  BUTTONS FUNCTIONS   (start menu & pause menu)    */
void depause_game(instance_t *instance);
void save_game(instance_t *instance);
void load_game(instance_t *instance);


/*  BUTTONS FUNCTIONS   (settings)    */
void set_windowed(instance_t *instance);
void set_fullscreen(instance_t *instance);
void settings_back(instance_t *instance);

map_t init_map(char *struct_path, instance_t *instance);
player init_player(instance_t *instance);
instance_t init_instance(void);
void gen_array_vertex(map_t *map);
sfRenderWindow *init_window(void);
menu_t init_start_menu(void);
menu_t init_pause_menu(void);
menu_t init_settings(void);
void init_bars(instance_t *instance);
void init_enemies(instance_t *instance);
sfText *init_text(char *str_text);
menu_button_t init_volume_button(void);
sfRectangleShape *init_volume_bg(void);
void init_game(instance_t *instance);
sfMusic *init_music(void);

void render_game_map(instance_t *instance);
void render_tutorial_map(instance_t *instance);
void render_game(instance_t *instance);
void render_start_menu(instance_t *instance);
void render_pause_menu(instance_t *instance);
void render_player(instance_t *instances);
void render_bars(instance_t *instances);
void render_front_enemy(instance_t *instance);
void render_back_enemy(instance_t *instance);
void render_tutorial(instance_t *instance);
void render_settings(instance_t *instance);
void render_volume(instance_t *instance);

void update_instance(instance_t *instance);
void update_bars(instance_t *instance);
void update_player(instance_t *instance);
void update_game(instance_t *instance);
void update_start_menu(instance_t *instance);
void update_pause_menu(instance_t *instance);
void update_enemy(instance_t *instance);
void update_tutorial(instance_t *instance);
void update_settings(instance_t *instance);
void update_button_color(menu_button_t *button);
void update_volume(instance_t *instance);

void manage_game_events(instance_t *instance, sfEvent event);
void manage_start_menu_events(instance_t *instance, sfEvent event);
void manage_pause_menu_events(instance_t *instance, sfEvent event);
void manage_tutorial_events(instance_t *instance, sfEvent event);
void manage_settings_events(instance_t *instance, sfEvent event);
void manage_key_pressed(instance_t *instance, sfEvent event);

void player_move(sfEvent event, instance_t *instance);

void destroy_map(map_t *map);
void destroy_instance(instance_t *instance);
