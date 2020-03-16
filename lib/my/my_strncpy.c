/*
** EPITECH PROJECT, 2019
** mystrncpy
** File description:
** cc
*/

char    *my_strncpy(char *dest, char const *src, int n)
{
    int i;
    int g;

    for (i = 0 ; i < n; i++)
        *(dest + i) = *(src + i);

    for (g = 0 ; *(src + g) != '\0'; g++);

    if (n > g)
        *(dest + i) = '\0';

    return (dest);
}
