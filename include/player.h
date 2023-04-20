/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** player.h
*/

#pragma once

#include <SFML/Graphics/Types.h>
#include <SFML/System/Types.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Vector2.h>
#include <stdint.h>
#include <stdbool.h>
#include "barector.h"

enum player_state {
    STRAIGHT,
    DRUGGED,
};

enum time_values {
    TIME_REGEN,
    TIME_MANA,
    TIME_ATTACK,
    TIME_SPRITE,

    TIME_COUNT
};

enum stats_value {
    STAT_DEFENSE,
    STAT_SPEED,
    STAT_STRENGTH,
    STAT_ATTACK_SPEED,
    STAT_REGEN,
    STAT_REGEN_TIME,
    STAT_ANGLE,
    STAT_COUNT
};

typedef struct player {
    sfClock *clock;
    sfSprite *sprite;
    sfFloatRect hitbox;
    sfVector2f map_pos;
    sfVector2f pos;
    uint8_t sprite_frame;
    bool is_walking;
    enum player_state state;
    float clocks[TIME_COUNT];
    float stats[STAT_COUNT];
    barector health;
    barector mana;
    unsigned nb_mana_pills;
} player;
