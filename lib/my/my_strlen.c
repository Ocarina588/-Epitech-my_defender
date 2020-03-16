/*
** EPITECH PROJECT, 2019
** task 03 day 04
** File description:
** ccc
*/

int    my_strlen(const char *str)
{
    int i = 0;
    if (!str)
        return (0);
    while ( *(str + i) != '\0' )
        i++;

    return (i);
}
