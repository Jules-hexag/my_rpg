/*
** EPITECH PROJECT, 2023
** amaurel
** File description:
** display the rain
*/

// alors la mystere: il faut que la pluie soit en couleur sur la map
//donc il faut trouver l'appel de la map (du coup les deux maps celle
// du jeu et celle du tutoriel)

#include "rpg.h"

int rain_gestion(instance_t *instance)
{
    sfColor shadow = (sfColor){150, 150, 150, 255};
    sfColor light = (sfColor){255, 255, 255, 255};

    if (instance->raining == true) {
        sfSprite_setColor(instance->instance->map[MAP_TUTORIAL], shadow);
        sfSprite_setColor(instance->instance->map[MAP_GAME], shadow);
        create_rain_particle(instance);
        create_rain_particle(instance);
        create_rain_particle(instance);
    } else {
        sfSprite_setColor(instance->instance->map[MAP_TUTORIAL], light);
        sfSprite_setColor(instance->instance->map[MAP_GAME], light);
    }
    return 0;
}

int destroy_game(instance_t *instance)
{
    sfClock_destroy(instance->particle_clock);
    sfRenderWindow_destroy(instance-window_params.window);
    free(instance);
    return 0;
}
