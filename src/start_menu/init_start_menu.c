/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** generate_menu
*/

#include <stdlib.h>
#include <SFML/Graphics/RectangleShape.h>
#include "menu.h"
#include "rpg.h"


//static init_button_rect(void)
//{
//    sfRectangleShape *rectangle = sfRectangleShape_create();
//    sfRectangleShape_setPosition(rectangle, pos);
//    sfRectangleShape_setSize(rectangle, size);
//    sfRectangleShape_setOutlineThickness(rectangle, (float) 2);
//    sfRectangleShape_setFillColor(rectangle, color);
//}

static menu_button_t init_button(sfVector2u win_size, int button_number)
{
    sfVector2i button_size = {win_size.x / 3, win_size.y / 8};
    int x_origin_button = win_size.x / 2 - button_size.x / 2;
    sfVector2f pos = {x_origin_button, 0};
    menu_button_t button = (menu_button_t) {
    .button = gen_rect_shape((sfVector2f) {button_size.x, button_size.y}, pos,
        (sfColor) {107, 107, 107, 255}),
    .origin = pos,
    .size = button_size,
    .button_state = NONE,
    .text = NULL,
    };

    return button;
}

menu_t init_start_menu(window_params_t *window_params)
{
    static menu_button_t buttons[SMB_COUNT];

    buttons[SMB_PLAY] = init_button(window_params->size, 1);
    buttons[SMB_QUIT] = init_button(window_params->size, 2);

    static menu_t menu = {.buttons = buttons};
    return menu;
}
