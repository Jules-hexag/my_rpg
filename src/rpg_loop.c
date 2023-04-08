/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** rpg_loop
*/

#include <stdlib.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderWindow.h>
#include "rpg.h"


static void (*const update_functions[]) (instance_t *) = {
    [IN_GAME] = &update_game,
    [IN_START_MENU] = &update_start_menu,
};

static void (*const render_functions[]) (instance_t *) = {
    [IN_GAME] = &render_game,
    [IN_START_MENU] = &render_start_menu,
};

static void (*const events_functions[]) (instance_t *, sfEvent) = {
    [IN_GAME] = &manage_game_events,
    [IN_START_MENU] = &manage_start_menu_events,
};

static void manage_rpg_events(instance_t *instance)
{
    sfRenderWindow *window = instance->window_params.window;
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        switch (event.type) {
            case sfEvtClosed:
                return sfRenderWindow_close(window);
            case sfEvtResized:
                resize_event(instance);
                break;
            default:
                events_functions[instance->menu_state](instance, event);
                break;
        }
    }
}

static void update_rpg(instance_t *instance)
{
    update_functions[instance->menu_state](instance);
}


static void render_rpg(instance_t *instance)
{
    sfRenderWindow *window = instance->window_params.window;
    sfRenderWindow_clear(window, sfBlack);
    render_functions[instance->menu_state](instance);
    sfRenderWindow_display(window);
}

void rpg_loop(instance_t *instance)
{
    while (sfRenderWindow_isOpen(instance->window_params.window)) {
        manage_rpg_events(instance);
        update_rpg(instance);
        render_rpg(instance);
    }
}
