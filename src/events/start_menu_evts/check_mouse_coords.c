/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** check_mouse_coords
*/

#include "start_menu.h"
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>

int check_mouse_coords(sfVector2f pos_mouse, start_menu_button *button)
{
    if (pos_mouse.x > button->origin.x && pos_mouse.x <
        (button->origin.x + button->size.x) && pos_mouse.y > button->origin.y &&
        pos_mouse.y < (button->origin.y + button->size.y)) {
        return MOUSE_IS_IN;
    } else {
        return MOUSE_IS_NOT_IN;
    }
}
