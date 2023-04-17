/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_text
*/

#include "rpg.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

sfText *init_text(char *str_text)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(
        "res/tragicastle/Tragicastle.otf");
    sfText_setFont(text, font);
    sfText_setString(text, str_text);
    sfText_setColor(text, sfWhite);
    return text;
}
