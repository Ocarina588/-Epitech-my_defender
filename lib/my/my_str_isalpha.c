/*
** EPITECH PROJECT, 2019
** cc
** File description:
** cccc
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    if (str[i] == '\0')
        return (1);

    while (str[i] != '\0')
    {
        if (str[i] < 'a' && str[i] > 'Z')
            return (0);

        if (str[i] < 'A' || str[i] > 'z')
            return (0);

        i++;
    }
    return (1);
}
