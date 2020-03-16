/*
** EPITECH PROJECT, 2019
** cc
** File description:
** cc
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    if (str[i] == '\0')
        return (1);

    while (str[i] != '\0')
    {
        if (str[i] < 'A' || str[i] > 'Z')
            return (0);

        i++;
    }

    return (1);
}
