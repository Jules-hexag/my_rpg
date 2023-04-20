/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_pause_menu
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Types.h>
#include "menu.h"
#include "rpg.h"

static void (*buttons_func[6])(void *instance) = {
    &depause_game,
    &save_game,
    &load_game,
    &pause_to_settings,
    &quit_game,
    NULL,
};

static void init_text_info_player(menu_button_t button)
{

}

static menu_button_t init_pm_button(int nb)
{
    char *text[5] = {"Resume", "Save", "Load", "Settings", "Quit"};
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(rectangle, (float) 2);
    sfRectangleShape_setOutlineColor(rectangle, sfWhite);
    menu_button_t button = {
    .button = rectangle,
    .button_state = NONE,
    .text = nb < PMB_BUTTON_COUNT ? init_text(text[nb]) : NULL,
    };

    return button;
}

menu_t init_pause_menu(void)
{
    static menu_button_t buttons[PMB_BUTTON_COUNT + 1];

    for (int pmb_init = 0; pmb_init < PMB_BUTTON_COUNT + 1; pmb_init++) {
        buttons[pmb_init] = init_pm_button(pmb_init);
        buttons[pmb_init].button_func = buttons_func[pmb_init];
        pmb_init == PMB_BUTTON_COUNT ? init_text_info_player(buttons[pmb_init]) : 0;
    }

    menu_t menu = {.buttons = buttons};
    return menu;
}
