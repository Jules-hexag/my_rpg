/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** render_start_menu.c
*/

#include "rpg.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>

void render_start_menu(instance_t *instance)
{
    sfRenderWindow *window = instance->window_params.window;
    sfRenderWindow_drawRectangleShape(window,
        instance->menus[START_MENU].buttons[0].button, NULL);
    sfRenderWindow_drawRectangleShape(window,
        instance->menus[START_MENU].buttons[1].button, NULL);
    sfRenderWindow_drawText(window, instance->menus->buttons[0].text, NULL);
    sfRenderWindow_drawText(window, instance->menus->buttons[1].text, NULL);
}
