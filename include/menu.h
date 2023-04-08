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

    #define MOUSE_IS_IN 0
    #define MOUSE_IS_NOT_IN 1

enum button_state_e {
    NONE = 0,
    HOVER,
    PRESSED,
};

enum start_menu_button {
    SMB_PLAY,
    SMB_QUIT,
    SMB_COUNT};

typedef struct {
    sfRectangleShape *button;
    sfVector2f origin;
    sfVector2i size;
    enum button_state_e button_state;
    sfText *text;
} menu_button_t;

typedef struct {
    menu_button_t *buttons;
} menu_t;

typedef struct {
    menu_t start_menu;
    menu_t pause_menu;
    menu_t inventory_menu;
} menu_group_t;

sfRectangleShape *gen_rect_shape(sfVector2f size, sfVector2f pos,
    sfColor color);

/*  FOLLOWING FUNCTIONS MANAGE THE POSITION OF THE MOUSE FOR
    HOVER AND CLICK ; COLORIZATION AND FUNCTIONS
*/

void hover_button(sfVector2f pos_mouse, menu_button_t *play_button);
int check_mouse_coords(sfVector2f pos_mouse, menu_button_t *menu_button);

void click_button(sfVector2f pos_mouse, menu_button_t *menu_button);

#endif /* !START_MENU_H_ */
