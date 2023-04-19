/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** generate_menu
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/System/Vector2.h>
#include "rpg.h"

static void (*buttons_func[5])(instance_t *instance) = {
    &play_game,
    &resume_game,
    &tutorial,
    &settings,
    &quit_game,
};

static menu_button_t init_sm_button(int nb)
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

    return button;
}

menu_t init_start_menu(void)
{
    static menu_button_t buttons[SMB_COUNT];

    for (int smb_init = 0; smb_init < SMB_COUNT; smb_init++) {
        buttons[smb_init] = init_sm_button(smb_init);
        buttons[smb_init].button_func = buttons_func[smb_init];
    }

    static menu_t menu = {.buttons = buttons};
    return menu;
}
