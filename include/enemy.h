/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** enemy.h
*/

#pragma once

#include <SFML/Graphics/Types.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Rect.h>
#include <stdbool.h>
#include "barector.h"

enum etp_stats {
    ETP_DIST,
    ETP_ANGLE,
    ETP_COUNT
};

typedef struct enemy {
    sfClock *clock;
    sfSprite *sprite;
    bool is_dead;
    float etp[ETP_COUNT];
    sfVector2f pos;
    barector health;
    sfFloatRect hitbox;
} enemy_t;
