/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** objects
*/

#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Texture.h>
#include "rpg.h"

static window_params_t init_window_params(void)
{
    window_params_t window_params = {0};

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
    return 0;
}

static volume_t init_volume(void)
{
    volume_t volume = {0};
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

    instance.menu_state = IN_START_MENU;
    instance.window_params = init_window_params();
    if (init_textures(&instance))
        return instance;
    instance.map[MAP_GAME] = init_map("res/maps/map1", &instance);
    instance.map[MAP_TUTORIAL] = init_map("res/maps/map1", &instance);
    instance.menus[START_MENU] = init_start_menu();
    instance.menus[SETTINGS] = init_settings();
    instance.player = init_player(&instance);
    init_enemies(&instance);
    init_bars(&instance);
    instance.volume = init_volume();
    return instance;
}
