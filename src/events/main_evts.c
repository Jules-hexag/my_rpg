/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main_evts
*/

#include "rpg.h"
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Event.h>

static void resize_event(sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtResized) {
        sfView *view = sfView_create();
        sfVector2u new_size = sfRenderWindow_getSize(window);
        sfView_setSize(view, (sfVector2f) {(float) new_size.x,
            (float) new_size.y});
        int n_x = new_size.x = new_size.x / 2;
        int n_y = new_size.y = new_size.y / 2;
        sfView_setCenter(view, (sfVector2f) {n_x, n_y});
        sfRenderWindow_setView(window, view);
    }
}

void events_management(sfRenderWindow *window)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        event.type == sfEvtClosed ? sfRenderWindow_close(window) : 0;
        event.type == sfEvtResized ? resize_event(event, window) : 0;
    }
}
