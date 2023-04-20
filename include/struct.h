/*
** EPITECH PROJECT, 2023
** amaurel
** File description:
** struct for rain
*/

#ifndef STRUCTURES_H_
    #define STRUCTURES_H_

    #include "global.h"
    #include "rpg.h"

typedef struct particles_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfColor color;
    int lifetime;
} particle_t;

typedef struct game_s
{
    sfView *view;
    sfView *hud_view;
    sfFloatRect view_rect;
    sfVector2f view_pos;
    sfClock *clock;
    linked_list_t *particles;
    linked_list_t *rain;
    bool raining;
    sfClock *particle_clock;
    bool paused;
} game_t;

#endif /* !STRUCTURES_H_ */
