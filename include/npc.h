/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** nps.h
*/

#pragma once

#include <SFML/Graphics/Types.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector2.h>

typedef struct npc {
    sfClock *npc_clock;
    sfSprite *sprite;
    sfVector2f pos;
    float etp_distance;
    sfMusic *music;
    sfText *text;
    // void (*func)(struct instance_s *);
} npc;
