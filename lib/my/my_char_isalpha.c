/*
** EPITECH PROJECT, 2019
** sdf
** File description:
** sdf
*/

int my_char_isalpha(char c)
{
    if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
        return (1);
    return (0);
}
