/*
** EPITECH PROJECT, 2023
** gen_map
** File description:
** destroy_instance.c
*/

#include "rpg.h"
#include "global.h"

void destroy_instance(instance_t *instance)
{
    destroy_map(instance->map);
}

int destroy_rain_particle(instance_t *instance)
{
    if (instance == NULL)
        return 0;
    if (instance->rain == NULL)
        return 0;
    while (instance->rain != NULL &&
    ((particle_t *)(instance->rain->data))->lifetime <= 0) {
        sfSprite_destroy(((particle_t *)instance->rain->data)->sprite);
        sfTexture_destroy(((particle_t *)instance->rain->data)->texture);
        instance->rain = remove_first_node(instance->rain);
    }
    return 0;
}

int destroy_all_rain_particle(instance_t *instance)
{
    if (instance == NULL)
        return 0;
    if (instance->rain == NULL)
        return 0;
    while (instance->rain != NULL) {
        sfSprite_destroy(((particle_t *)instance->rain->data)->sprite);
        sfTexture_destroy(((particle_t *)instance->rain->data)->texture);
        instance->rain = remove_first_node(instance->rain);
    }
    return 0;
}

int destroy_all(instance_t *instance)
{
    destroy_rain_particle(instance);
    destroy_all_rain_particle(instance);
    destroy_instance(instance);
    return (0);
}
