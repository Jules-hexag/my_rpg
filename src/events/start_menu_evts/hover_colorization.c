/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** hover_colorization
*/

#include "start_menu.h"
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/RectangleShape.h>
#include <stdio.h>

void hover_button(sfVector2f pos_mouse, start_menu_button *menu_button)
{
    if (check_mouse_coords(pos_mouse, menu_button) == MOUSE_IS_IN) {
        menu_button->button_state = HOVER;
        sfRectangleShape_setFillColor(menu_button->button,
            (sfColor) {107, 0, 40, 255});
    } else  {
        menu_button->button_state = NONE;
        sfRectangleShape_setFillColor(menu_button->button,
            (sfColor) {107, 107, 107, 255});
    }
}
