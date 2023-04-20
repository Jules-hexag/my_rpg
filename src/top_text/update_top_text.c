/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_top_text.c
*/


#include <SFML/Graphics/Text.h>
#include "rpg.h"


void update_top_text_pos(instance_t *intance)
{
    sfVector2i pos;
    pos.y = intance->window_params.size.y - 150;
    pos.x = 10;
    sfVector2f new_pos =
        sfRenderWindow_mapPixelToCoords(intance->window_params.window,
            pos, NULL);
    sfText_setPosition(intance->text.text_sprite, new_pos);
}

void update_top_text(instance_t *instance)
{
    update_top_text_pos(instance);
    if (instance->rpg_state == IN_GAME && !instance->talked_to_npc) {
        sfText_setUnicodeString(instance->text.text_sprite, (sfUint32 *)
            L"Appuie sur E pour parler au PNJ");
    }
    if (instance->rpg_state == IN_GAME && instance->talked_to_npc) {
        sfText_setUnicodeString(instance->text.text_sprite, (sfUint32 *)
            L"Tue tous les zombies.\nVoilà ta quête jeune aventurier");
    }
    if (instance->rpg_state == IN_GAME
        && instance->dead_enemies == instance->enemy_count[MAP_GAME]) {
        sfText_setUnicodeString(instance->text.text_sprite, (sfUint32 *)
            L"Bravo tu as fini le jeu !\n");
    }
    if (instance->rpg_state == IN_TUTORIAL) {
        sfText_setUnicodeString(instance->text.text_sprite, (sfUint32 *)
            L"Déplace toi avec ZQSD,\nAttaque avec la barre d'espace,\n"
            L"Met le jeu en pause avec Echap");
    }
}
