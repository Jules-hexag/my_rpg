/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_settings
*/

#include <SFML/Graphics/RectangleShape.h>
#include "rpg.h"

static void (*buttons_func[3])(void *instance) = {
    &set_windowed,
    &set_fullscreen,
    &settings_back,
};

static menu_button_t init_stt_button(int nb)
{
    char *text[3] = {"Windowed", "Full Screen", "Back"};
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(rectangle, (float) 2);
    sfRectangleShape_setOutlineColor(rectangle, sfWhite);
    menu_button_t button = {
    .button = rectangle,
    .button_state = NONE,
    .text = init_text(text[nb]),
    };

    return button;
}

menu_t init_settings(void)
{
    static menu_button_t buttons[STT_BUTTON_COUNT];

    for (int stt_init = 0; stt_init < STT_BUTTON_COUNT; stt_init++) {
        buttons[stt_init] = init_stt_button(stt_init);
        buttons[stt_init].button_func = buttons_func[stt_init];
    }
    static menu_t menu = {.buttons = buttons};
    return menu;
}
