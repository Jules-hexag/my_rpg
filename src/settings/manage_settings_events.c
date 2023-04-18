/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** manage_settings_events
*/

#include "rpg.h"

static void mouse_moved_evt(window_params_t *window_stats, menu_t *start_menu)
{
    sfVector2i pos_mouse_pix = sfMouse_getPositionRenderWindow(
        window_stats->window);
    sfVector2f pos_mouse = sfRenderWindow_mapPixelToCoords(window_stats->window,
        pos_mouse_pix, NULL);

    for (int i = 0; i < STT_BUTTON_COUNT; i++) {
        if (sfFloatRect_contains(&start_menu->buttons[i].rect, pos_mouse.x,
            pos_mouse.y)) {
            start_menu->buttons[i].button_state = HOVER;
            continue;
        }
        start_menu->buttons[i].button_state = NONE;
    }
}

static void mouse_released_evt(instance_t *instance, menu_t *start_menu)
{
    for (int i = 0; i < STT_BUTTON_COUNT; i++) {
        if (start_menu->buttons[i].button_state == PRESSED)
            start_menu->buttons[i].button_func(instance);
    }
}

void manage_settings_events(instance_t *instance, sfEvent event)
{
    window_params_t *window_stats = &instance->window_params;
    menu_t *settings = &instance->menus[SETTINGS];
    switch (event.type) {
        case sfEvtMouseMoved:
            mouse_moved_evt(window_stats, settings);
            break;
        case sfEvtMouseButtonReleased:
            mouse_released_evt(instance, settings);
            break;
        default:
            break;
    }
}
