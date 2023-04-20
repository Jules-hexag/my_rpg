/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** window_params.h
*/

#pragma once

#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

typedef struct window_params {
    sfRenderWindow *window;
    sfView *view;
    sfVector2u size;
    sfSprite *menu_background;
} window_params;
