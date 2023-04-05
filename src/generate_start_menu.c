/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** generate_menu
*/

#include <stdlib.h>
#include "menu.h"
#include "rpg.h"

static menu_button fill_struct(sfVector2f pos, sfVector2i button_size)
{
    menu_button init_button = (menu_button) {
    .button = gen_rect_shape(&(sfVector2f) {button_size.x, button_size.y}, &pos,
        (sfColor) {107, 107, 107, 255}),
    .origin = pos,
    .size = button_size,
    .button_state = NONE,
    .text = NULL,
    };

    return init_button;
}

static menu_button init_button(sfVector2u win_size, int button_number)
{
    sfVector2i button_size = {win_size.x / 3, win_size.y / 8};
    int x_origin_button = win_size.x / 2 - button_size.x / 2;
    sfVector2f pos = {x_origin_button, 0};
    switch (button_number) {
        case 1:
            pos.y = 40;
            break;
        case 2:
            pos.y = 180;
            break;
        default:
            break;
    }

    return fill_struct(pos, button_size);
}

menu generate_start_menu(window_t *window_stats)
{
    static menu_button all[2];
    all[0] = init_button(window_stats->size, 1);
    all[1] = init_button(window_stats->size, 2);
    menu all_instances = (menu) {
        .memory = 3,
        .buttons = all,
    };
    return all_instances;
}
