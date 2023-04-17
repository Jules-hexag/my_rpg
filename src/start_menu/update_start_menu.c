/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_start_menu.c
*/

#include "rpg.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>


static const int nmax = 3;


static const sfColor smb_colors[3] = {
    [NONE] = {107, 107, 107, 255},
    [HOVER] = {107, 0, 40, 255},
    [PRESSED] = {107, 107, 107, 255},
};

static void update_button_size(menu_button_t *button, window_params_t *params)
{
    sfVector2u const win_size = params->size;
    sfVector2f size = {win_size.x / 3, win_size.y / 10};
    button->size = size;
    sfRectangleShape_setSize(button->button, size);
}

static void update_button_pos(menu_button_t *button, window_params_t *params,
    int nb)
{
    sfVector2u const win_size = params->size;
    sfVector2f const button_size = button->size;
    const int di = (win_size.y - (SMB_COUNT) * button_size.y) / (SMB_COUNT + 1);
    sfVector2i posi = {win_size.x / 2 - button_size.x / 2,
        di + nb * (di + button_size.y)};
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(params->window, posi,
        NULL);
    sfRectangleShape_setPosition(button->button, pos);
}

static void update_button_text(menu_button_t *button, window_params_t *params)
{
    sfVector2f pos = sfRectangleShape_getPosition(button[0].button);
    pos.x = pos.x + button->size.x / 3;
    pos.y += 10;

    sfVector2u window_size = sfRenderWindow_getSize(params->window);

    sfText_setCharacterSize(button->text, window_size.x * 30 / 800);

    sfText_setPosition(button->text, (sfVector2f) {pos.x, pos.y});
}

static void update_button_color(menu_button_t *button)
{
    if (button->button_state == HOVER && sfMouse_isButtonPressed(sfMouseLeft))
        button->button_state = PRESSED;
    sfRectangleShape_setFillColor(button->button,
        smb_colors[button->button_state]);
}

void update_start_menu(instance_t *instance)
{
    menu_t *menu = &instance->menus[START_MENU];
    for (int i = 0; i < SMB_COUNT; i++) {
        update_button_size(&menu->buttons[i], &instance->window_params);
        update_button_pos(&menu->buttons[i], &instance->window_params, i);
        menu->buttons[i].rect = sfRectangleShape_getGlobalBounds(
            menu->buttons[i].button);
        update_button_color(&menu->buttons[i]);
        update_button_text(&menu->buttons[i], &instance->window_params);
    }
}
