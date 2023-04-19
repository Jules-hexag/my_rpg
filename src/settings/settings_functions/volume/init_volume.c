/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_volume
*/

#include <SFML/Audio/Types.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Types.h>
#include "rpg.h"

sfMusic *init_music(void)
{
    return NULL;
}

menu_button_t init_volume_button(void)
{
    char *text = "Volume : 100%";
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(rectangle, (float) 2);
    sfRectangleShape_setOutlineColor(rectangle, sfWhite);
    menu_button_t button = {
    .button = rectangle,
    .button_state = NONE,
    .text = init_text(text),
    };

    return button;
}

sfRectangleShape *init_volume_bg(void)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rectangle, (sfColor) {20, 20, 20, 200});
    return rectangle;
}
