/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouse_clicked
*/

#include "menu.h"
#include "rpg.h"
#include <SFML/Graphics/Types.h>

void mouse_moved_evt(window_t *window_stats, menu *start_menu)
{
    sfVector2i pos_mouse_pix = sfMouse_getPositionRenderWindow(
        window_stats->window);
    sfVector2f pos_mouse = sfRenderWindow_mapPixelToCoords(window_stats->window,
        pos_mouse_pix, NULL);
    hover_button(pos_mouse, &start_menu->buttons[0]);
    hover_button(pos_mouse, &start_menu->buttons[1]);
}

void mouse_clicked_evt(window_t *window_stats, menu *start_menu)
{
    sfVector2i pos_mouse_pix = sfMouse_getPositionRenderWindow(
        window_stats->window);
    sfVector2f pos_mouse = sfRenderWindow_mapPixelToCoords(window_stats->window,
        pos_mouse_pix, NULL);
    click_button(pos_mouse, &start_menu->buttons[0]);
    click_button(pos_mouse, &start_menu->buttons[1]);
}

int mouse_released_evt(window_t *window_stats, menu *start_menu)
{
    sfVector2i pos_mouse_pix = sfMouse_getPositionRenderWindow(
        window_stats->window);
    sfVector2f pos_mouse = sfRenderWindow_mapPixelToCoords(window_stats->window,
        pos_mouse_pix, NULL);
    if (check_mouse_coords(pos_mouse,
        &start_menu->buttons[0]) == MOUSE_IS_IN) {
        return START_GAME;
    }
    if (check_mouse_coords(pos_mouse,
        &start_menu->buttons[1]) == MOUSE_IS_IN) {
        return EXIT_PROGRAM;
    }
    hover_button(pos_mouse, &start_menu->buttons[0]);
    hover_button(pos_mouse, &start_menu->buttons[1]);
    return NORMAL_RETURN;
}
