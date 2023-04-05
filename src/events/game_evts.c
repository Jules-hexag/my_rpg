/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main_evts
*/

#include "rpg.h"
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Event.h>

void resize_event(sfEvent event, window_t *window_stats)
{
    if (event.type == sfEvtResized) {
        sfView *view = sfView_create();
        sfVector2u new_size = sfRenderWindow_getSize(window_stats->window);
        window_stats->size = new_size;
        sfView_setSize(view, (sfVector2f) {(float) new_size.x,
            (float) new_size.y});
        int size_x = new_size.x = new_size.x / 2;
        int size_y = new_size.y = new_size.y / 2;
        sfView_setCenter(view, (sfVector2f) {size_x, size_y});
        sfRenderWindow_setView(window_stats->window, view);
    }
}

void game_events_management(window_t *window_stats)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window_stats->window, &event)) {
        event.type == sfEvtClosed ? sfRenderWindow_close(window_stats->window)
            : 0;
        event.type == sfEvtResized ? resize_event(event, window_stats) : 0;
    }
}
