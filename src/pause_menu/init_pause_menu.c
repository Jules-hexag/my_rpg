/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_pause_menu
*/

#include <SFML/Graphics/RectangleShape.h>
#include "rpg.h"

static void (*buttons_func[5])(instance_t *instance) = {
    &depause_game,
    &save_game,
    &load_game,
    &pause_to_settings,
    &quit_game,
};

static menu_button_t init_pm_button(int nb)
{
    char *text[5] = {"Resume", "Save", "Load", "Settings", "Quit"};
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

menu_t init_pause_menu(void)
{
    static menu_button_t buttons[PMB_BUTTON_COUNT];

    for (int pmb_init = 0; pmb_init < PMB_BUTTON_COUNT; pmb_init++) {
        buttons[pmb_init] = init_pm_button(pmb_init);
        buttons[pmb_init].button_func = buttons_func[pmb_init];
    }

    menu_t menu = {.buttons = buttons};
    return menu;
}
