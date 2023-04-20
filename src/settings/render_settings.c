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
    window_params win_obj = instance->window_params;
    sfRenderWindow *window = instance->window_params.window;
    menu_button_t *buttons = instance->menus[SETTINGS].buttons;
    sfRenderWindow_drawSprite(window, win_obj.menu_background, NULL);
    for (int stt_rect = 0; stt_rect < STT_BUTTON_COUNT; stt_rect++)
        sfRenderWindow_drawRectangleShape(window,
        instance->menus[SETTINGS].buttons[stt_rect].button, NULL);
    for (int stt_text = 0; stt_text < STT_BUTTON_COUNT; stt_text++)
        sfRenderWindow_drawText(window, buttons[stt_text].text, NULL);
    render_volume(instance);
}
