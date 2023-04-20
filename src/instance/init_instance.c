/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** objects
*/

#include <SFML/Audio/Music.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Texture.h>
#include "rpg.h"

static window_params init_window_params(void)
{
    window_params window_params;

    window_params.window = init_window();
    window_params.size = (sfVector2u) {800, 800};
    window_params.menu_background = gen_sprite_shape("res/start_menu.jpg",
        (sfVector2f) {0, 0});

    return window_params;
}

static int init_textures(instance_t *instance)
{
    if ((instance->texture[TEXTURE_PLAYER] = sfTexture_createFromFile(
        "res/player_sprite.png", NULL)) == NULL)
        return 1;
    if ((instance->texture[TEXTURE_TILESET] = sfTexture_createFromFile(
        "res/tileset.png", NULL)) == NULL)
        return 1;
    if ((instance->texture[TEXTURE_ENEMY] = sfTexture_createFromFile(
        "res/zombie.png", NULL)) == NULL)
        return 1;
    if ((instance->texture[TEXTURE_NPC] = sfTexture_createFromFile(
        "res/npc.png", NULL)) == NULL)
        return 1;
    return 0;
}

static volume_t init_volume(void)
{
    volume_t volume;
    volume.current_volume = init_volume_button();
    volume.volume_bg = init_volume_bg();
    volume.music = init_music();
    volume.volume = 1;

    return volume;
}

/**
 * @brief Create an instances object containing all important data
 *
 * @return instance_t*
 */
instance_t init_instance(void)
{
    instance_t instance = {0};
    instance.rpg_state = IN_START_MENU;
    instance.window_params = init_window_params();
    if (init_textures(&instance))
        return (instance_t) {0};
    instance.map[MAP_GAME] = init_map("res/maps/map", &instance);
    instance.map[MAP_TUTORIAL] = init_map("res/maps/map_tuto", &instance);
    instance.menus[START_MENU] = init_start_menu();
    instance.menus[SETTINGS] = init_settings();
    init_game(&instance);
    init_bars(&instance);
    instance.text = init_top_text();
    instance.volume = init_volume();
    instance.menus[PAUSE] = init_pause_menu();
    instance.sounds[0] = sfMusic_createFromFile("res/music/button.wav");
    instance.sounds[1] = sfMusic_createFromFile("res/music/dead.wav");
    instance.sounds[2] = sfMusic_createFromFile("res/music/zombies.wav");
    sfMusic_setLoop(instance.sounds[2], sfTrue);
    return instance;
}
