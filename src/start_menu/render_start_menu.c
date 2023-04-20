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
    menu_button_t *buttons = instance->menus[START_MENU].buttons;
    sfRenderWindow_drawSprite(window, instance->window_params.menu_background,
        NULL);
    for (int smb_rect = 0; smb_rect < SMB_BUTTON_COUNT; smb_rect++)
        sfRenderWindow_drawRectangleShape(window,
        instance->menus[START_MENU].buttons[smb_rect].button, NULL);
    for (int smb_text = 0; smb_text < SMB_BUTTON_COUNT; smb_text++)
        sfRenderWindow_drawText(window, buttons[smb_text].text, NULL);
}
