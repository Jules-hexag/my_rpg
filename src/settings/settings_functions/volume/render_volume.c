/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** render_volume
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include "rpg.h"

void render_volume(instance_t *instance)
{
    sfRenderWindow *window = instance->window_params.window;
    volume_t vol = instance->volume;
    sfRenderWindow_drawRectangleShape(window, vol.volume_bg, NULL);
    sfRenderWindow_drawRectangleShape(window, vol.current_volume.button, NULL);
    sfRenderWindow_drawText(window, vol.current_volume.text, NULL);
}
