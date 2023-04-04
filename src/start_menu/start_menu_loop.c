/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** start_menu_loop
*/

#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "start_menu.h"
#include "rpg.h"

start_menu_button fill_struct(sfVector2f pos, sfVector2i button_size)
{
    start_menu_button init_button = (start_menu_button) {
    .button = gen_rect_shape(&(sfVector2f) {START_MENU_BUTTON_SIZE}, &pos,
        (sfColor) {107, 107, 107, 255}),
    .origin = pos,
    .size = button_size,
    .button_state = NONE,
    .text = NULL,
    };

    return init_button;
}

start_menu_button init_button(sfRenderWindow *window, int button_number)
{
    sfVector2i button_size = {START_MENU_BUTTON_SIZE};
    int x_origin_button = WIN_WIDTH / 2 - button_size.x / 2;
    sfVector2f pos = {x_origin_button, 0};
    switch (button_number) {
        case 1:
            pos.y = 40;
            break;
        case 2:
            pos.y = 180;
            break;
        default:
            break;
    }

    return fill_struct(pos, button_size);
}

static start_menu generate_start_instances(sfRenderWindow *window)
{
    start_menu all_instances = (start_menu) {
        .play_button = init_button(window, 1),
        .quit_game_button = init_button(window, 2),
    };

    return all_instances;
}

int start_menu_loop(sfRenderWindow *window)
{
    start_menu all_start_menu_instances = generate_start_instances(window);
    int event_return = 0;

    while (sfRenderWindow_isOpen(window)) {
        event_return = start_events_management(window,
            &all_start_menu_instances);
        if (event_return == EXIT_PROGRAM) return EXIT_PROGRAM;
        if (event_return == START_GAME) return START_GAME;
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawRectangleShape(window,
            all_start_menu_instances.play_button.button, NULL);
        sfRenderWindow_drawRectangleShape(window,
            all_start_menu_instances.quit_game_button.button, NULL);
        sfRenderWindow_display(window);
    }
    return 0;
}
// avant le return 0 de le fin :
//   free et destroy tout
