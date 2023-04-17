/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** generate_menu
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/System/Vector2.h>
#include "menu.h"
#include "rpg.h"

void (*buttons_func[5])(instance_t *instance) = {
    &play_game,
    &resume_game,
    &tutorial,
    &settings,
    &quit_game,
};

static menu_button_t init_button(window_params_t *window_params, int nb)
{
    char *text[5] = {"Play", "Resume", "Tutorial", "Settings", "Quit"};
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

menu_t init_start_menu(window_params_t *window_params)
{
    static menu_button_t buttons[SMB_COUNT];

    for (int smb_init = 0; smb_init < SMB_COUNT; smb_init++) {
        buttons[smb_init] = init_button(window_params, smb_init);
        buttons[smb_init].button_func = buttons_func[smb_init];
    }

    static menu_t menu = {.buttons = buttons};
    return menu;
}
