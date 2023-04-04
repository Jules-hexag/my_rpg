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

void (*start_menus_events[2])(window_t *window_stats,
    menu *start_menu) = {
    &mouse_moved_evt,
    &mouse_clicked_evt,
};

void start_menu_mouse_moved(window_t *window_stats, menu *start_menu)
{
    start_menus_events[0](window_stats, start_menu);
}

void start_menu_mouse_clicked(window_t *window_stats, menu *start_menu)
{
    start_menus_events[1](window_stats, start_menu);
}

int start_events_management(window_t *window_stats, menu *start_menu)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window_stats->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window_stats->window);
            return EXIT_PROGRAM;
        }
        event.type == sfEvtResized ? resize_event(event, window_stats) : 0;
        event.type == sfEvtMouseMoved ? start_menu_mouse_moved(window_stats,
            start_menu) : 0;
        event.type == sfEvtMouseButtonPressed ? start_menu_mouse_clicked(
            window_stats, start_menu) : 0;
        if (event.type == sfEvtMouseButtonReleased) {
            return mouse_released_evt(window_stats, start_menu);
        }
    }
    return NORMAL_RETURN;
}
