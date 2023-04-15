/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** move_player
*/

#include "rpg.h"
#include <SFML/Window/Event.h>

void player_move(sfEvent event, instance_t *instance)
{
    event.key.code == sfKeyZ ? (instance->player.map_pos.y - 2 <= 0 ? 0 :
                                instance->player.map_pos.y--) : 0;
    event.key.code == sfKeyQ ? (instance->player.map_pos.x - 6 <= 0 ? 0 :
                                instance->player.map_pos.x--) : 0;
    event.key.code == sfKeyS ? (instance->player.map_pos.y + 2 >=
        instance->map->size.y * 16 ? 0 : instance->player.map_pos.y++) : 0;
    event.key.code == sfKeyD ? (instance->player.map_pos.x + 6 >=
        instance->map->size.x * 16 ? 0 : instance->player.map_pos.x++) : 0;
}
