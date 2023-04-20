/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** menu.h
*/

#pragma once

#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Audio.h>

enum button_state_e {
    NONE,
    HOVER,
    PRESSED,
};

typedef struct menu_button_s {
    sfRectangleShape *button;
    sfFloatRect rect;
    sfVector2f origin;
    sfVector2f size;
    enum button_state_e button_state;
    sfText *text;
    void (*button_func) (void *instance);
} menu_button_t;

typedef struct volume_s {
    sfMusic *music;
    sfRectangleShape *volume_bg;
    menu_button_t current_volume;
    float volume;
} volume_t;

typedef struct menu_s {
    menu_button_t *buttons;
} menu_t;
