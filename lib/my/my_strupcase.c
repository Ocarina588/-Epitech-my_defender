/*
** EPITECH PROJECT, 2019
** my-strupcase
** File description:
** cc
*/

char *my_strupcase(char *str)
{
    int i = 0;
    while (1)
    {
        if ( str[i] == '\0' )
            return (str);

        if ( str[i] <= 'z' && str[i] >= 'a' )
            str[i] -= 'a' - 'A';

        i++;
    }
}
