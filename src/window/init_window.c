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

sfView *init_view(void)
{
    sfView *view = sfView_create();
    sfVector2f center = {800.f / 2, 800.f / 2};

    sfView_setCenter(view, center);
    sfView_setSize(view, (sfVector2f) {160, 160});
    return view;
}

sfRenderWindow *init_window(void)
{
    const char title[] = "RPG NAME";
    sfVideoMode mode = {800, 800, 32};
    sfRenderWindow *window =
        sfRenderWindow_create(mode, title, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);

    sfView *view = init_view();
    sfRenderWindow_setView(window, view);
    sfView_destroy(view);

    return window;
}
