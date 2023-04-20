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
    // void (*func)(struct instance_s *);
} npc;
