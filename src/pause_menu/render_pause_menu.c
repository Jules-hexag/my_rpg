/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** render_pause_menu
*/

#include "rpg.h"

void render_pause_menu(instance_t *instance)
{
    sfRenderWindow *window = instance->window_params.window;
    menu_button_t *buttons = instance->menus[PAUSE].buttons;
    sfRenderWindow_drawSprite(window, instance->window_params.menu_background,
        NULL);
    for (int pmb_rect = 0; pmb_rect < PMB_BUTTON_COUNT; pmb_rect++)
        sfRenderWindow_drawRectangleShape(window,
        instance->menus[PAUSE].buttons[pmb_rect].button, NULL);
    for (int pmb_text = 0; pmb_text < PMB_BUTTON_COUNT; pmb_text++)
        sfRenderWindow_drawText(window, buttons[pmb_text].text, NULL);
}
