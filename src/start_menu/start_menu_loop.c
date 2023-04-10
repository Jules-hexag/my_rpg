/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** start_menu_loop
*/

#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "menu.h"
#include "rpg.h"

void render_start_menu(instance_t *instance)
{
    sfRenderWindow *window = instance->window_params.window;
    sfRenderWindow_drawRectangleShape(window,
        instance->menus[START_MENU].buttons[0].button, NULL);
    sfRenderWindow_drawRectangleShape(window,
        instance->menus[START_MENU].buttons[1].button, NULL);
}

void update_start_menu(instance_t *instance)
{
    sfRenderWindow *window = instance->window_params.window;
    sfRenderWindow_clear(window, sfBlack);
}

int start_menu_loop(window_params_t *window_stats, menu_t *start_menu)
{
    int event_return = 0;
    while (sfRenderWindow_isOpen(window_stats->window)) {
        event_return = 1;
        if (event_return == EXIT_PROGRAM) return EXIT_PROGRAM;
        if (event_return == START_GAME) return START_GAME;
        sfRenderWindow_clear(window_stats->window, sfBlack);
        sfRenderWindow_drawRectangleShape(window_stats->window,
            start_menu->buttons[0].button, NULL);
        sfRenderWindow_drawRectangleShape(window_stats->window,
            start_menu->buttons[1].button, NULL);
        sfRenderWindow_display(window_stats->window);
    }
    return 0;
}
// avant le return 0 de le fin :
//   free et destroy tout
