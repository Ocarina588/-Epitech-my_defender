/*
** EPITECH PROJECT, 2019
** mystrcmp
** File description:
** cc
*/

int    my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int diff = 0;

    while (1){

        if (s1[i] != s2[i]){

            diff = s1[i] - s2[i];
            return (diff);
        }

        if (s1[i] == '\0' && s2[i] == '\0')
            return (0);
        i++;
    }
}
