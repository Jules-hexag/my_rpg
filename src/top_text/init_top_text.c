/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_top_text.c
*/

#include <SFML/Graphics/Text.h>
#include "rpg.h"

top_text init_top_text(void)
{
    top_text top_text;
    my_strcat(top_text.text, "Tue tous les zombies...\n"
        "Voila ta quete jeune aventurier");
    top_text.text_sprite = init_text(top_text.text);
    sfText_setOutlineColor(top_text.text_sprite, sfBlack);
    sfText_setOutlineThickness(top_text.text_sprite, 2);
    return top_text;
}
