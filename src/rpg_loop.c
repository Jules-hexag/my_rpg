/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** rpg_loop
*/

#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/RenderWindow.h>
#include "rpg.h"

static void (*const events_functions[]) (instance_t *, sfEvent) = {
    [IN_GAME] = &manage_game_events,
    [IN_START_MENU] = &manage_start_menu_events,
    [IN_TUTORIAL] = &manage_tutorial_events,
    [IN_SETTINGS] = &manage_settings_events,
};

static void (*const update_functions[]) (instance_t *) = {
    [IN_GAME] = &update_game,
    [IN_START_MENU] = &update_start_menu,
    [IN_TUTORIAL] = &update_tutorial,
    [IN_SETTINGS] = &update_settings,
};

static void (*const render_functions[]) (instance_t *) = {
    [IN_GAME] = &render_game,
    [IN_START_MENU] = &render_start_menu,
    [IN_TUTORIAL] = &render_tutorial,
    [IN_SETTINGS] = &render_settings,
};

void resize_event(instance_t *instance)
{
    window_params_t *window_params = &instance->window_params;
    sfVector2u new_size = sfRenderWindow_getSize(window_params->window);
    sfView *view = sfView_create();
    sfView_setSize(view, (sfVector2f) {(float) new_size.x,
        (float) new_size.y});
    sfRenderWindow_setView(window_params->window, view);
    sfView_destroy(view);
}

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
    if (!sfRenderWindow_hasFocus(instance->window_params.window))
        return;
    update_instance(instance);
    update_functions[instance->menu_state](instance);
}

static void render_rpg(instance_t *instance)
{
    if (!sfRenderWindow_hasFocus(instance->window_params.window))
        return;
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
