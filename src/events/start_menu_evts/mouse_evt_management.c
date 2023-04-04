/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouse_clicked
*/

#include "start_menu.h"
#include "rpg.h"
#include <SFML/Graphics/Types.h>

void mouse_moved_evt(sfRenderWindow *window, start_menu *start_instances)
{
    sfVector2i pos_mouse_pix = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos_mouse = sfRenderWindow_mapPixelToCoords(window,
        pos_mouse_pix, NULL);
    hover_button(pos_mouse, &start_instances->play_button);
    hover_button(pos_mouse, &start_instances->quit_game_button);
}

void mouse_clicked_evt(sfRenderWindow *window, start_menu *start_instances)
{
    sfVector2i pos_mouse_pix = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos_mouse = sfRenderWindow_mapPixelToCoords(window,
        pos_mouse_pix, NULL);
    click_button(pos_mouse, &start_instances->play_button);
    click_button(pos_mouse, &start_instances->quit_game_button);
}

int mouse_released_evt(sfRenderWindow *window, start_menu *start_instances)
{
    sfVector2i pos_mouse_pix = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos_mouse = sfRenderWindow_mapPixelToCoords(window,
        pos_mouse_pix, NULL);
    if (check_mouse_coords(pos_mouse,
        &start_instances->play_button) == MOUSE_IS_IN) {
        return START_GAME;
    }
    if (check_mouse_coords(pos_mouse,
        &start_instances->quit_game_button) == MOUSE_IS_IN) {
        return EXIT_PROGRAM;
    }
    hover_button(pos_mouse, &start_instances->play_button);
    hover_button(pos_mouse, &start_instances->quit_game_button);
    return NORMAL_RETURN;
}
