/*
** EPITECH PROJECT, 2019
** strlowcase
** File description:
** cc
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (1)
    {
        if ( str[i] == '\0' )
            return (str);

        if ( str[i] <= 'Z' && str[i] >= 'A' )
            str[i] -= 'A' - 'a';

        i++;
    }

    return (str);
}
