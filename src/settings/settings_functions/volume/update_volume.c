/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_volume
*/

#include "rpg.h"
#include <SFML/Audio/Music.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>

static void update_volume_selector(instance_t *instance, sfVector2f cdsmouse,
    sfVector2i pos_mouse_pix)
{
    sfRenderWindow *window = instance->window_params.window;
    menu_button_t bt_curr = instance->volume.current_volume;
    sfFloatRect rect_bg = sfRectangleShape_getGlobalBounds(
        instance->volume.volume_bg);
    if (instance->volume.current_volume.button_state == PRESSED &&
        (cdsmouse.x < (rect_bg.left + rect_bg.width) &&
        cdsmouse.x > rect_bg.left)) {
        sfVector2f pos_rect = sfRectangleShape_getPosition(bt_curr.button);
        sfVector2i pos_rect_i = sfRenderWindow_mapCoordsToPixel(window,
            pos_rect, NULL);
        sfVector2i new_pos = {pos_mouse_pix.x - bt_curr.size.x, pos_rect_i.y};
        sfVector2f pos = sfRectangleShape_getPosition(bt_curr.button);
        sfVector2f new_pos_coords = sfRenderWindow_mapPixelToCoords(window,
            new_pos, NULL);
        new_pos_coords.y = pos.y;
        new_pos_coords.x += 10;
        sfRectangleShape_setPosition(bt_curr.button, new_pos_coords);
        instance->volume.volume = (cdsmouse.x - rect_bg.left) / (rect_bg.width);
    }
}

static void update_items_size(instance_t *instance)
{
    sfVector2u win_size = instance->window_params.size;
    sfVector2f bg_size = {win_size.x * 0.8, win_size.y / 40};
    sfVector2f current_size = {win_size.x / 40, win_size.y / 20};
    sfRectangleShape_setSize(instance->volume.volume_bg, bg_size);
    sfRectangleShape_setSize(instance->volume.current_volume.button,
        current_size);
    instance->volume.current_volume.size = current_size;
}

static void update_items_pos(instance_t *instance)
{
    sfRenderWindow *window = instance->window_params.window;
    sfVector2u win_size = instance->window_params.size;
    sfVector2i bg_pos = {win_size.x / 2 - (win_size.x * 0.8) / 2,
        win_size.y / 10};
    if (instance->volume.volume == 1) {
        sfVector2i cpos = {win_size.x / 2 + win_size.x * 0.8 / 2, win_size.y
            / 10 - instance->volume.current_volume.size.y / 4};
        sfVector2f pos_c = sfRenderWindow_mapPixelToCoords(window, cpos, NULL);
        sfRectangleShape_setPosition(instance->volume.current_volume.button,
            pos_c);
    }

    sfVector2f pos = sfRenderWindow_mapPixelToCoords(window, bg_pos, NULL);
    sfRectangleShape_setPosition(instance->volume.volume_bg, pos);
}

static void update_text(instance_t *instance)
{
    sfRenderWindow *window = instance->window_params.window;
    sfVector2u win_size = instance->window_params.size;
    sfVector2i text_pos = {win_size.x / 2 - 100, win_size.y / 10 + 50};

    sfVector2f text_coords = sfRenderWindow_mapPixelToCoords(window,
        text_pos, NULL);
    sfText_setPosition(instance->volume.current_volume.text, text_coords);
    char vol[16] = "Volume: ";
    int volume = (int) (instance->volume.volume * 100);
    my_strcat(vol, my_itoa(volume));
    sfText_setString(instance->volume.current_volume.text, vol);
}

void update_volume(instance_t *instance)
{
    update_items_size(instance);
    update_items_pos(instance);
    update_button_color(&instance->volume.current_volume);

    sfRenderWindow *window = instance->window_params.window;
    sfVector2i pos_mouse_pix = sfMouse_getPositionRenderWindow(window);
    sfVector2f cdsmouse = sfRenderWindow_mapPixelToCoords(window,
        pos_mouse_pix, NULL);
    update_volume_selector(instance, cdsmouse, pos_mouse_pix);
    sfMusic_setVolume(instance->volume.music, instance->volume.volume * 100);
    update_text(instance);
}
