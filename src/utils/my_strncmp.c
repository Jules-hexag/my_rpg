/*
** EPITECH PROJECT, 2022
** task07
** File description:
** difference btwn 2 str
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int it = 0;
    int res = 0;

    while (s1[it] != '\0' || s2[it] != '\0') {
        if (s1[it] - s2[it] < 0) {
            res = s1[it] - s2[it];
            return res;
        }
        if (s1[it] - s2[it] > 0) {
            res = s1[it] - s2[it];
            return res;
        }
        if (it == n - 1)
            break;
        it++;
    }
    return 0;
}
