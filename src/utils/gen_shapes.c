/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** gen_shapes
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Color.h>
#include <SFML/System/Vector2.h>

sfRectangleShape *gen_rect_shape(sfVector2f *size, sfVector2f *pos,
    sfColor color)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfRectangleShape_setPosition(rectangle, *pos);
    sfRectangleShape_setSize(rectangle, *size);
    sfRectangleShape_setOutlineThickness(rectangle, (float) 2);
    sfRectangleShape_setFillColor(rectangle, color);

    return rectangle;
}
