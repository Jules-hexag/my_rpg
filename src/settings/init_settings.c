/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_settings
*/

#include <SFML/Graphics/RectangleShape.h>
#include "rpg.h"

static void (*buttons_func[2])(instance_t *instance) = {
    set_windowed,
    set_fullscreen,
};

static menu_button_t init_STTbutton(window_params_t *window_params, int nb)
{
    char *text[2] = {"Windowed", "Full Screen"};
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(rectangle, (float) 2);
    sfRectangleShape_setOutlineColor(rectangle, sfWhite);
    menu_button_t button = {
    .button = rectangle,
    .button_state = NONE,
    .text = init_text(text[nb]),
    };
    window_params->menu_background = gen_sprite_shape("res/start_menu.jpg",
        (sfVector2f) {0, 0});

    return button;
}

menu_t init_settings(window_params_t *window_params)
{
    static menu_button_t buttons[STT_BUTTON_COUNT];

    for (int stt_init = 0; stt_init < STT_BUTTON_COUNT; stt_init++) {
        buttons[stt_init] = init_STTbutton(window_params, stt_init);
        buttons[stt_init].button_func = buttons_func[stt_init];
    }

    static menu_t menu = {.buttons = buttons};
    return menu;
}
