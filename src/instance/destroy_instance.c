/*
** EPITECH PROJECT, 2023
** gen_map
** File description:
** destroy_instance.c
*/

#include "rpg.h"

void destroy_instance(instance_t *instance)
{
    destroy_map(instance->map);
}
