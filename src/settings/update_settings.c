/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_settings
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <math.h>
#include "rpg.h"

static void update_stt_button_size(menu_button_t *button,
    window_params_t *params)
{
    sfVector2u const win_size = params->size;
    sfVector2f size = {win_size.x / 4, win_size.y / 6};
    button->size = size;
    sfRectangleShape_setSize(button->button, size);
}

static void update_stt_button_pos(menu_button_t *button,
    window_params_t *params, int nb)
{
    sfVector2u const win_size = params->size;
    sfVector2f const button_size = button->size;
    sfVector2i posi = {(win_size.x / 2 - button_size.x *
        pow((-1), nb) - win_size.y / 10),
        win_size.y / 2};
    if (nb == STT_BACK) {
        posi.x = win_size.x / 2 - button_size.x / 2;
        posi.y = win_size.y - (button_size.y + 20);
    }
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(params->window, posi,
        NULL);
    sfRectangleShape_setPosition(button->button, pos);
}

static void update_stt_button_text(menu_button_t *button,
    window_params_t *params)
{
    sfVector2f pos = sfRectangleShape_getPosition(button[0].button);
    sfVector2f button_size = sfRectangleShape_getSize(button[0].button);
    pos.x += button_size.x / 5;
    pos.y += button_size.y / 3;
    sfSprite_setPosition(params->menu_background, (sfVector2f)
        sfRenderWindow_mapPixelToCoords(params->window,
        (sfVector2i) {0, 0}, NULL));

    sfVector2u window_size = sfRenderWindow_getSize(params->window);
    sfText_setCharacterSize(button->text, window_size.x * 24 / 800);
    sfText_setPosition(button->text, (sfVector2f) {pos.x, pos.y});
}

void update_settings(instance_t *instance)
{
    menu_t *menu = &instance->menus[SETTINGS];
    for (int i = 0; i < STT_BUTTON_COUNT; i++) {
        update_stt_button_size(&menu->buttons[i], &instance->window_params);
        update_stt_button_pos(&menu->buttons[i], &instance->window_params, i);
        menu->buttons[i].rect = sfRectangleShape_getGlobalBounds(
            menu->buttons[i].button);
        update_button_color(&menu->buttons[i]);
        update_stt_button_text(&menu->buttons[i], &instance->window_params);
        update_volume(instance);
    }
}
