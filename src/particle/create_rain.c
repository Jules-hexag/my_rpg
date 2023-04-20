/*
** EPITECH PROJECT, 2023
** amaurel
** File description:
** Make it rain !
*/

#include "rpg.h"

int create_rain_particle(instance_t *instance)
{
    particle_t *particle = malloc(sizeof(particle_t));
    float rand_scale = rand() % 3;

    particle->sprite = sfSprite_create();
    particle->texture = sfTexture_createFromFile\
    ("res/particle/white_particle.png", NULL);
    if (particle == NULL || particle->texture == NULL || particle-> sprite ==
    NULL)
        return 84;
    sfSprite_setTexture(particle->sprite, particle->texture, sfFalse);
    particle->pos = ((sfVector2f)\
    {.x = instance->view_pos.x + 250 - rand() % 500 , \
    .y = instance->view_pos.y - 250});
    particle->lifetime = 50;
    sfSprite_setPosition(particle->sprite, particle->pos);
    sfSprite_setScale(particle->sprite, (sfVector2f)\
    {rand_scale / 4, rand_scale * -1});
    sfSprite_setColor(particle->sprite, (sfColor){200, 200, 250, 200});
    instance->rain = add_end_node(instance->rain, particle);
    return 0;
}

int update_rain_particle(instance_t *instance)
{
    particle_t *particle = NULL;
    linked_list_t *index = instance->rain;

    if (index == NULL)
        return 0;
    particle = index->data;
    while (index != NULL) {
        particle = index->data;
        particle->pos.y += (rand() % 50);
        particle->pos.x -= (rand() % 3);
        sfSprite_setPosition(particle->sprite, particle->pos);
        index = index->next;
        particle->lifetime -= 1;
    }
    return 0;
}
int draw_rain_particle(instance_t *instance)
{
    particle_t *particle = NULL;
    linked_list_t *index = instance->rain;

    if (index == NULL)
        return 0;
    while (index != NULL) {
        particle = index->data;
        sfRenderWindow_drawSprite(instance->map[MAP_GAME].render, \
        particle->sprite, NULL);
        index = index->next;
    }
    return 0;
}
