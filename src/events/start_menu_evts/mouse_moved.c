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
