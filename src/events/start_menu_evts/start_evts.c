/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** start_evts
*/

#include "start_menu.h"
#include "rpg.h"
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Event.h>
#include <SFML/Graphics/RenderWindow.h>

void (*start_menus_events[2])(sfRenderWindow *window,
    start_menu *start_menus) = {
    &mouse_moved_evt,
    &mouse_clicked_evt,
};

void start_menu_mouse_moved(sfRenderWindow *window, start_menu *start_instances)
{
    start_menus_events[0](window, start_instances);
}

void start_menu_mouse_clicked(sfRenderWindow *window,
    start_menu *start_instances)
{
    start_menus_events[1](window, start_instances);
}

int start_events_management(sfRenderWindow *window, start_menu *start_instances)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return EXIT_PROGRAM;
        }
        event.type == sfEvtResized ? resize_event(event, window) : 0;
        event.type == sfEvtMouseMoved ? start_menu_mouse_moved(window,
            start_instances) : 0;
        event.type == sfEvtMouseButtonPressed ? start_menu_mouse_clicked(
            window, start_instances) : 0;
        if (event.type == sfEvtMouseButtonReleased) {
            return mouse_released_evt(window, start_instances);
        }
    }
    return NORMAL_RETURN;
}
