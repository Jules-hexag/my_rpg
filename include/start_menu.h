/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** start_menu
*/

#ifndef START_MENU_H_
    #define START_MENU_H_

    #include <SFML/Graphics/Types.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Window/Event.h>

    #define START_GAME 0
    #define EXIT_PROGRAM 1
    #define NORMAL_RETURN 2

    #define START_MENU_BUTTON_SIZE 400, 100

    #define MOUSE_IS_IN 0
    #define MOUSE_IS_NOT_IN 1

enum button_state_e {
    NONE = 0,
    HOVER,
    PRESSED,
};

typedef struct {
    sfRectangleShape *button;
    sfVector2f origin;
    sfVector2i size;
    enum button_state_e button_state;
    sfText *text;
} start_menu_button;

typedef struct {
    start_menu_button play_button;
    start_menu_button quit_game_button;
} start_menu;

int start_menu_loop(sfRenderWindow *window);

int start_events_management(sfRenderWindow *window, start_menu *start_instances);

sfRectangleShape *gen_rect_shape(sfVector2f *size, sfVector2f *pos,
    sfColor color);

/*  FOLLOWING FUNCTIONS MANAGE THE POSITION OF THE MOUSE FOR
    HOVER AND CLICK ; COLORIZATION AND FUNCTIONS
*/

void hover_button(sfVector2f pos_mouse, start_menu_button *play_button);
int check_mouse_coords(sfVector2f pos_mouse, start_menu_button *menu_button);

void mouse_moved_evt(sfRenderWindow *window, start_menu *start_instances);
void mouse_clicked_evt(sfRenderWindow *window, start_menu *start_instances);

int mouse_released_evt(sfRenderWindow *window, start_menu *start_instances);

void click_button(sfVector2f pos_mouse, start_menu_button *menu_button);

#endif /* !START_MENU_H_ */
