/*
** EPITECH PROJECT, 2019
** sdf
** File description:
** sdfa
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    if (str[i] == '\0')
        return (1);

    while (str[i] != '\0')
    {
        if (str[i] < 32 && str[i] >= 0)
            return (0);

        i++;
    }

    return (1);
}
