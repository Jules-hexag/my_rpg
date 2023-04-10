/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** start_evts
*/

#include "menu.h"
#include "rpg.h"
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Event.h>
#include <SFML/Graphics/RenderWindow.h>

static void (*const start_menus_events[])(window_params_t *window_stats,
    menu_t *start_menu) = {
    [0 ... sfEvtMouseWheelScrolled] = NULL,
    [sfEvtMouseMoved] = &mouse_moved_evt,
    [sfEvtMouseButtonPressed] = &mouse_clicked_evt,
    [sfEvtMouseButtonReleased] = &mouse_released_evt,
    [sfEvtMouseEntered ... sfEvtCount - 1] = NULL,
};

void start_menu_mouse_moved(window_params_t *window_stats, menu_t *start_menu)
{
    start_menus_events[0](window_stats, start_menu);
}

void start_menu_mouse_clicked(window_params_t *window_stats, menu_t *start_menu)
{
    start_menus_events[1](window_stats, start_menu);
}

void manage_start_menu_events(instance_t *instance, sfEvent event)
{
    window_params_t *window_stats = &instance->window_params;
    menu_t *start_menu = &instance->menus[START_MENU];
    if (event.type == sfEvtMouseMoved)
        return start_menu_mouse_moved(window_stats, start_menu);
    if (event.type == sfEvtMouseButtonPressed)
        return start_menu_mouse_clicked(window_stats, start_menu);
    if (event.type == sfEvtMouseButtonReleased)
        mouse_released_evt(window_stats, start_menu);
}
