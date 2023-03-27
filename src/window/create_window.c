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
    sfVideoMode mode = {WIN_WIDTH, WIN_HEIGHT, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, title, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);

    sfView *view = sfView_create();
    sfView_setSize(view, (sfVector2f) {WIN_WIDTH, WIN_HEIGHT});
    int width_center = WIN_WIDTH / 2;
    int height_center = WIN_HEIGHT / 2;
    sfView_setCenter(view, (sfVector2f) {width_center, height_center});
    sfRenderWindow_setView(window, view);

    return window;
}
