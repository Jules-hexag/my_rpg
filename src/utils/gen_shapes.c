/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** gen_shapes
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/System/Vector2.h>

sfSprite *gen_sprite_shape(char *texture_path, sfVector2f pos)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(texture_path, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

sfRectangleShape *gen_rect_shape(sfVector2f size, sfColor color)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setOutlineThickness(rectangle, (float) 2);
    sfRectangleShape_setFillColor(rectangle, color);

    return rectangle;
}
