/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_npc.c
*/

#include <SFML/Graphics/Sprite.h>
#include "rpg.h"

npc init_npc(instance_t *instance, sfVector2f pos)
{
    npc npc;
    npc.npc_clock = sfClock_create();
    npc.sprite = sfSprite_create();
    npc.pos.y = pos.y;
    npc.pos.x = pos.x;
    npc.music = sfMusic_createFromFile("res/music/npc.mp3");
    sfSprite_setTexture(npc.sprite, instance->texture[TEXTURE_NPC], sfTrue);
    sfSprite_setPosition(npc.sprite, pos);
    sfSprite_setScale(npc.sprite, (sfVector2f) {4, 4});
    sfSprite_setOrigin(npc.sprite, (sfVector2f) {8, 24});
    return npc;
}
