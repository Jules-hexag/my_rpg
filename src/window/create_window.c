/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_window
*/

#include "rpg.h"
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <string.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window.h>

sfRenderWindow *init_window(void)
{
    const char title[] = "RPG NAME";
    sfVideoMode mode = {800, 800, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, title, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);

    sfView *view = sfView_create();
    sfView_setSize(view, (sfVector2f) {800, 800});
    int width_center = 800 / 2;
    int height_center = 800 / 2;
    sfView_setCenter(view, (sfVector2f) {width_center, height_center});
    sfRenderWindow_setView(window, view);

    return window;
}
