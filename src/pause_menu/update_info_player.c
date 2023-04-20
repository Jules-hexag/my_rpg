/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_info_player
*/

#include <SFML/Graphics/RectangleShape.h>
#include "menu.h"
#include "rpg.h"

void update_info_player_rect_size(instance_t *instance)
{
    menu_button_t button = instance->menus[PAUSE].buttons[PMB_BUTTON_COUNT];
    sfVector2u const win_size = instance->window_params.size;
    sfVector2f size = {win_size.x / 4.2, win_size.y / 1.3};
    button.size = size;
    sfRectangleShape_setSize(button.button, size);
}

void update_info_player_rect_pos(instance_t *instance)
{
    menu_button_t button = instance->menus[PAUSE].buttons[PMB_BUTTON_COUNT];
    sfVector2u const win_size = instance->window_params.size;
    sfVector2i posi = {win_size.x - (button.size.x + win_size.x / 3.5), win_size.y / 8};
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(instance->window_params.window, posi,
        NULL);
    update_button_color(&button);
    sfRectangleShape_setPosition(button.button, pos);
}

void update_text_info_player(instance_t *instance)
{
    char info_p[256] = "  PLAYER INFO  \n";
    char *stats_title[4] = {"Level: ", "Exp: ", "Speed: ", "Regen: "};
    // char *stats[4] = {my_itoa((unsigned int) instance->player.)}

    for (int i = 0; i < 4; i++) {
        // my_strcat(info_p, stats[i]);
        // my_strcat(info_p, my_itoa());
    }
}
