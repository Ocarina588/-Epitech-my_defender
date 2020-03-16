/*
** EPITECH PROJECT, 2019
** mystrncmp
** File description:
** cc
*/

int    my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int diff = 0;

    while (i < n )
    {
        if (s1[i] != s2[i]){

            diff = s1[i] - s2[i];
            return (diff);
        }

        if (s1[i] == '\0' && s2[i] == '\0')
            return (0);
        i++;
    }
    return (diff);
}
