/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** manage_settings_events
*/

#include "rpg.h"
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>

static void manage_volume_button(menu_button_t *volume_current,
    sfVector2f pos_mouse)
{
    if (volume_current->button_state != NONE && sfMouse_isButtonPressed(
        sfMouseLeft)) {
        volume_current->button_state = PRESSED;
        return;
    }
    volume_current->rect = sfRectangleShape_getGlobalBounds(
        volume_current->button);
    if (sfFloatRect_contains(&volume_current->rect, pos_mouse.x,
            pos_mouse.y)){
        volume_current->button_state = HOVER;
    } else {
        volume_current->button_state = NONE;
    }
}

static void mouse_moved_evt(window_params_t *window_stats,
    menu_t *settings_menu, menu_button_t *volume_current)
{
    sfVector2i pos_mouse_pix = sfMouse_getPositionRenderWindow(
        window_stats->window);
    sfVector2f pos_mouse = sfRenderWindow_mapPixelToCoords(window_stats->window,
        pos_mouse_pix, NULL);

    for (int i = 0; i < STT_BUTTON_COUNT; i++) {
        if (sfFloatRect_contains(&settings_menu->buttons[i].rect, pos_mouse.x,
            pos_mouse.y)) {
            settings_menu->buttons[i].button_state = HOVER;
            continue;
        }
        settings_menu->buttons[i].button_state = NONE;
    }
    manage_volume_button(volume_current, pos_mouse);
}

static void mouse_released_evt(instance_t *instance, menu_t *start_menu)
{
    for (int i = 0; i < STT_BUTTON_COUNT; i++)
        if (start_menu->buttons[i].button_state == PRESSED)
            start_menu->buttons[i].button_func(instance);

}

void manage_settings_events(instance_t *instance, sfEvent event)
{
    window_params_t *window_stats = &instance->window_params;
    menu_t *settings = &instance->menus[SETTINGS];
    menu_button_t *volume_current = &instance->volume.current_volume;
    switch (event.type) {
        case sfEvtMouseMoved:
            mouse_moved_evt(window_stats, settings, volume_current);
            break;
        case sfEvtMouseButtonReleased:
            mouse_released_evt(instance, settings);
            break;
        default:
            break;
    }
}
