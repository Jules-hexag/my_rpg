/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main_evts
*/

#include "rpg.h"
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Event.h>

void resize_event(instance_t *instance)
{
    window_params_t *window_params = &instance->window_params;
    sfVector2u new_size = sfRenderWindow_getSize(window_params->window);
    sfView *view = sfView_create();
    sfView_setSize(view, (sfVector2f) {(float) new_size.x,
        (float) new_size.y});
    sfView_zoom(view, 0.25f);
    sfRenderWindow_setView(window_params->window, view);
    sfView_destroy(view);
}

void game_events_management(instance_t *instance)
{
    sfRenderWindow *window = instance->window_params.window;
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        event.type == sfEvtClosed ? sfRenderWindow_close(window)
            : 0;
        event.type == sfEvtResized ? resize_event(instance) : 0;
    }
}
