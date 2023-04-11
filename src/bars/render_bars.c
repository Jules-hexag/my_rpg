/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** render_bars
*/

#include "rpg.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>

void render_bars(instance_t *instances)
{
    sfRenderWindow *window = instances->window_params.window;

    sfSprite *health_bg = instances->bars[B_HEALTH].background;
    sfSprite *health_current = instances->bars[B_HEALTH].current;

    sfSprite *mana_bg = instances->bars[B_MANA].background;
    sfSprite *mana_current = instances->bars[B_MANA].current;

    sfRenderWindow_drawSprite(window, health_bg, NULL);
    sfRenderWindow_drawSprite(window, health_current, NULL);

    sfRenderWindow_drawSprite(window, mana_bg, NULL);
    sfRenderWindow_drawSprite(window, mana_current, NULL);
}
