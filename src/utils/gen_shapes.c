/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** gen_shapes
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Color.h>
#include <SFML/System/Vector2.h>

sfRectangleShape *gen_rect_shape(sfVector2f size, sfColor color)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setOutlineThickness(rectangle, (float) 2);
    sfRectangleShape_setFillColor(rectangle, color);

    return rectangle;
}
