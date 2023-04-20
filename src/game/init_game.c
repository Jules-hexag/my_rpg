/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_game.c
*/

#include <stdio.h>
#include "rpg.h"

void save_game(void *ptr)
{
    instance_t *instance = (instance_t *) ptr;
    FILE *save_file = fopen("save.myrpg", "wb+");
    save save = {.player = instance->player,
        .dead_enemies = instance->dead_enemies,
        .talked_to_npc = instance->talked_to_npc};
    for (int i = 0; i < instance->enemy_count[MAP_GAME]; i++)
        save.enemy[i] = instance->enemy[MAP_GAME][i];
    fwrite(&save, sizeof(save), 1, save_file);
    fclose(save_file);
    depause_game(ptr);
}

void init_game(instance_t *instance)
{
    instance->player = init_player(instance);
    init_enemies(instance);
    instance->npc = init_npc(instance,(sfVector2f) {2 * 64, 2 * 64});
}

void load_enemies(instance_t *instance, save save)
{
    for (int i = 0; i < instance->enemy_count[MAP_GAME]; i++) {
        sfClock *clock = instance->enemy[MAP_GAME][i].clock;
        sfSprite *sprite = instance->enemy[MAP_GAME][i].sprite;
        instance->enemy[MAP_GAME][i] = save.enemy[i];
        instance->enemy[MAP_GAME][i].sprite = sprite;
        instance->enemy[MAP_GAME][i].clock = clock;
    }
}

void load_game(void *ptr)
{
    instance_t *instance = (instance_t *) ptr;
    save save;
    FILE *save_file = fopen("save.myrpg", "rb");
    if (save_file == NULL) return;
    fread(&save, sizeof(save), 1, save_file);
    fclose(save_file);
    sfSprite *sprite = instance->player.sprite;
    sfClock *clock = instance->player.clock;
    instance->player = save.player;
    instance->player.sprite = sprite;
    instance->player.clock = clock;
    instance->dead_enemies = save.dead_enemies;
    instance->talked_to_npc = save.talked_to_npc;
    load_enemies(instance, save);
    depause_game(ptr);
}
