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

void start_menu_mouse_moved(sfRenderWindow *window, sfEvent *event,
    start_menu *start_instances)
{
    if (event->type == sfEvtMouseMoved) {
        mouse_moved_evt(window, start_instances);
    }
}

int start_events_management(sfRenderWindow *window, start_menu *start_instances)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        event.type == sfEvtClosed ? sfRenderWindow_close(window) : 0;
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return EXIT_PROGRAM;
        }
        event.type == sfEvtResized ? resize_event(event, window) : 0;
        start_menu_mouse_moved(window, &event, start_instances);
    }
    return NORMAL_RETURN;
}
