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

const sfColor inactive_color = {107, 107, 107, 255};

void quit_game(instance_t *instance)
{
    sfRenderWindow_close(instance->window_params.window);
}

void play_game(instance_t *instance)
{
    instance->menu_state = IN_GAME;
}

static menu_button_t init_button(window_params_t *window_params, int nb)
{
    char *text = nb == 1 ? "Play" : "Quit";
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(rectangle, (float) 2);
    sfRectangleShape_setOutlineColor(rectangle, sfWhite);
    menu_button_t button = {
    .button = rectangle,
    .button_state = NONE,
    .text = init_text(text),
    };
    window_params->menu_background = gen_sprite_shape("res/start_menu.jpg",
        (sfVector2f) {0, 0});

    return button;
}

menu_t init_start_menu(window_params_t *window_params)
{
    static menu_button_t buttons[SMB_COUNT];

    buttons[SMB_PLAY] = init_button(window_params, 1);
    buttons[SMB_PLAY].button_func = &play_game;
    buttons[SMB_QUIT] = init_button(window_params, 2);
    buttons[SMB_QUIT].button_func = &quit_game;

    static menu_t menu = {.buttons = buttons};
    return menu;
}
