/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** hover_colorization
*/

#include "menu.h"
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/RectangleShape.h>
#include <stdio.h>

void hover_button(sfVector2f pos_mouse, menu_button_t *button)
{
    if (check_mouse_coords(pos_mouse, button) == MOUSE_IS_IN) {
        button->button_state = HOVER;
        sfRectangleShape_setFillColor(button->button,
            (sfColor) {107, 0, 40, 255});
    } else  {
        button->button_state = NONE;
        sfRectangleShape_setFillColor(button->button,
            (sfColor) {107, 107, 107, 255});
    }
}
