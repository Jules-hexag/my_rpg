/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myhunter-jules.fradin
** File description:
** itoa
*/

#include <stdlib.h>

char *my_itoa(unsigned int nbr)
{
    int size = 0;
    int nbr_cp = nbr;
    while (nbr_cp > 0) {
        nbr_cp /= 10;
        size++;
    }
    if (size == 0) {
        char *str = malloc(sizeof(char) + 1);
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    char *str = malloc(sizeof(char) * size + 1);
    for (int i = size - 1; i >= 0; i--) {
        str[i] = (nbr % 10) + '0';
        nbr /= 10;
    }
    str[size] = '\0';
    return str;
}
