/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_info_player
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Text.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include "menu.h"
#include "player.h"
#include "rpg.h"

void update_info_player_rect_size(instance_t *instance)
{
    menu_button_t button = instance->menus[PAUSE].buttons[PMB_BUTTON_COUNT];
    sfVector2u const win_size = instance->window_params.size;
    sfVector2f size = {win_size.x / 4.2, win_size.y / 3.9};
    button.size = size;
    sfRectangleShape_setSize(button.button, size);
}

void update_info_player_rect_pos(instance_t *instance)
{
    menu_button_t button = instance->menus[PAUSE].buttons[PMB_BUTTON_COUNT];
    sfVector2u const win_size = instance->window_params.size;
    sfVector2i posi = {win_size.x - (button.size.x + win_size.x / 3.5),
        win_size.y / 8};
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(
        instance->window_params.window, posi, NULL);
    update_button_color(&button);
    sfRectangleShape_setPosition(button.button, pos);
}

static void update_text_info_player_sequel(instance_t *instance, char *info_p)
{
    sfText *text = instance->menus[PAUSE].buttons[PMB_BUTTON_COUNT].text;
    sfVector2u const win_size = instance->window_params.size;
    menu_button_t button = instance->menus[PAUSE].buttons[PMB_BUTTON_COUNT];
    sfVector2i rect_pos = {win_size.x - (button.size.x + win_size.x / 3.5),
        win_size.y / 8};
    sfText_setString(text, info_p);
    sfVector2f text_pos = sfRenderWindow_mapPixelToCoords(
        instance->window_params.window,
        (sfVector2i) {rect_pos.x + 10, rect_pos.y + 10}, NULL);
    sfText_setPosition(text, text_pos);
    if (win_size.x == 800) sfText_setCharacterSize(text, 22);
    if (win_size.x == 1920) sfText_setCharacterSize(text, 28);
}

void update_text_info_player(instance_t *instance)
{
    char info_p[256] = "  -PLAYER INFO-  \n\n\n";
    char *stats_title[4] = {"Level: ", "Exp: ", "Speed: ", "Regen: "};
    char *stats[4] = {my_itoa((unsigned int) (instance->player.level + 1)),
        my_itoa((unsigned int) (instance->player.exp - 1)),
        my_itoa((unsigned int) instance->player.stats[STAT_SPEED]),
        my_itoa((unsigned int) (instance->player.stats[STAT_REGEN] * 100))};

    for (int i = 0; i < 4; i++) {
        my_strcat(info_p, stats_title[i]);
        my_strcat(info_p, stats[i]);
        my_strcat(info_p, "\n");
    }
    update_text_info_player_sequel(instance, info_p);
}
