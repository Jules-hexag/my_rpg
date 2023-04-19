/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** manage_pause_menu_events
*/

#include "rpg.h"

static void mouse_moved_evt(window_params_t *window_stats, menu_t *pause_menu)
{
    sfVector2i pos_mouse_pix = sfMouse_getPositionRenderWindow(
        window_stats->window);
    sfVector2f pos_mouse = sfRenderWindow_mapPixelToCoords(window_stats->window,
        pos_mouse_pix, NULL);

    for (int i = 0; i < PMB_BUTTON_COUNT; i++) {
        if (sfFloatRect_contains(&pause_menu->buttons[i].rect, pos_mouse.x,
            pos_mouse.y)) {
            pause_menu->buttons[i].button_state = HOVER;
            continue;
        }
        pause_menu->buttons[i].button_state = NONE;
    }
}

static void mouse_released_evt(instance_t *instance, menu_t *pause_menu)
{
    for (int i = 0; i < PMB_BUTTON_COUNT; i++) {
        if (pause_menu->buttons[i].button_state == PRESSED)
            pause_menu->buttons[i].button_func(instance);
    }
}

void manage_pause_menu_events(instance_t *instance, sfEvent event)
{
    window_params_t *window_stats = &instance->window_params;
    menu_t *pause_menu = &instance->menus[PAUSE];
    switch (event.type) {
        case sfEvtMouseMoved:
            mouse_moved_evt(window_stats, pause_menu);
            break;
        case sfEvtMouseButtonReleased:
            mouse_released_evt(instance, pause_menu);
            break;
        default:
            break;
    }
}
