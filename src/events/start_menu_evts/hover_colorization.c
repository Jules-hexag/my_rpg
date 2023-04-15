/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** hover_colorization
*/

#include "rpg.h"
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/RectangleShape.h>
#include <stdio.h>

extern sfColor inactive_color;
static const sfColor hover_color = {107, 0, 40, 255};

void hover_button(sfVector2f pos_mouse, menu_button_t *button)
{

    if (sfFloatRect_contains(&button->rect, pos_mouse.x, pos_mouse.y)) {
        button->button_state = HOVER;
    } else  {
        button->button_state = NONE;
    }
}
