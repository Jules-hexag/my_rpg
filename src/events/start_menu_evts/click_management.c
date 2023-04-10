/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** click_management
*/

#include "menu.h"
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Types.h>

void click_button(sfVector2f pos_mouse, menu_button_t *menu_button)
{
    if (check_mouse_coords(pos_mouse, menu_button) == MOUSE_IS_IN &&
        menu_button->button_state == HOVER) {
        menu_button->button_state = PRESSED;
        sfRectangleShape_setFillColor(menu_button->button,
            (sfColor) {66, 1, 9, 255});
    }
}
