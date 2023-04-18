/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** render_settings
*/

#include "rpg.h"
#include <SFML/Graphics/RenderWindow.h>

void render_settings(instance_t *instance)
{
    window_params_t win_obj = instance->window_params;
    sfRenderWindow *window = instance->window_params.window;
    menu_button_t *buttons = instance->menus[SETTINGS].buttons;
    sfRenderWindow_drawSprite(window, win_obj.menu_background, NULL);
    for (int smb_rect = 0; smb_rect < STT_BUTTON_COUNT; smb_rect++)
        sfRenderWindow_drawRectangleShape(window,
        instance->menus[SETTINGS].buttons[smb_rect].button, NULL);
    for (int smb_text = 0; smb_text < STT_BUTTON_COUNT; smb_text++)
        sfRenderWindow_drawText(window, buttons[smb_text].text, NULL);
}
