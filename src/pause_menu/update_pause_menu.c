/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_pause_menu
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <unistd.h>
#include "rpg.h"

static void (*info_player[3])(instance_t *instance) = {
    &update_info_player_rect_size,
    &update_info_player_rect_pos,
    &update_text_info_player,
};

static void update_pm_button_size(menu_button_t *button,
    window_params *params)
{
    sfVector2u const win_size = params->size;
    sfVector2f size = {win_size.x / 3, win_size.y / 10};
    button->size = size;
    sfRectangleShape_setSize(button->button, size);
}

static void update_pm_button_pos(menu_button_t *button, window_params *params,
    int nb)
{
    sfVector2u const win_size = params->size;
    sfVector2f const button_size = button->size;
    const int di = (win_size.y - (PMB_BUTTON_COUNT) * button_size.y) /
        (PMB_BUTTON_COUNT + 1);
    sfVector2i posi = {win_size.x / 2 - button_size.x / 2,
        di + nb * (di + button_size.y)};
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(params->window, posi,
        NULL);
    sfRectangleShape_setPosition(button->button, pos);
}

static void update_pm_button_text(menu_button_t *button,
    window_params *params)
{
    sfVector2f pos = sfRectangleShape_getPosition(button[0].button);
    pos.x = pos.x + button->size.x / 4;
    pos.y += 10;
    sfSprite_setPosition(params->menu_background, (sfVector2f)
        sfRenderWindow_mapPixelToCoords(params->window,
        (sfVector2i) {0, 0}, NULL));

    sfVector2u window_size = sfRenderWindow_getSize(params->window);

    sfText_setCharacterSize(button->text, window_size.x * 30 / 800);

    sfText_setPosition(button->text, (sfVector2f) {pos.x, pos.y});
}

void update_pause_menu(instance_t *instance)
{
    menu_t *menu = &instance->menus[PAUSE];
    window_params window_params = instance->window_params;
    for (int i = 0; i < PMB_BUTTON_COUNT; i++) {
        update_pm_button_size(&menu->buttons[i], &window_params);
        update_pm_button_pos(&menu->buttons[i], &window_params, i);
        menu->buttons[i].rect = sfRectangleShape_getGlobalBounds(
            menu->buttons[i].button);
        update_button_color(&menu->buttons[i]);
        update_pm_button_text(&menu->buttons[i], &window_params);
    }
    for (int i = 0; i < 2; i++)
        info_player[i](instance);
}
