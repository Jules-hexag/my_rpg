/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_volume
*/

#include <SFML/Audio/Types.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include "rpg.h"

void change_volume(instance_t *instance)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(
        instance->window_params.window);
    sfRectangleShape *rectangle = instance->volume.current_volume.button;
    sfVector2f rect_pos = sfRectangleShape_getPosition(rectangle);
    rect_pos.x = pos_mouse.x;
    sfRectangleShape_setPosition(rectangle, rect_pos);
}

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
    .button_func = change_volume,
    };

    return button;
}

sfRectangleShape *init_volume_bg(void)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rectangle, (sfColor) {20, 20, 20, 200});
    return rectangle;
}
