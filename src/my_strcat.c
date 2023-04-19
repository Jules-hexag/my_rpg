/*
** EPITECH PROJECT, 2022
** strcat
** File description:
** vsuieiuo
*/

char *my_strcat(char *dest, const char *src)
{
    int i = 0;
    int taille_dest = 0;
    while (dest[taille_dest] != '\0')
        taille_dest++;

    for (i; src[i] != '\0'; i++) {
        dest[taille_dest + i] = src[i];
    }

    dest[taille_dest + i] == '\0';

    return dest;
}
