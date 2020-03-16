/*
** EPITECH PROJECT, 2019
** istrncat
** File description:
** sdf
*/

#include "my.h"

char *my_istrncat(char *dest, char const *src, int nb , int j)
{
    int len = my_strlen(dest);
    int i;

    for ( i = 0; i < nb && src[i+j] != '\0' ; i++)
        dest[len + i] = src[i+j];

    dest[len + i] = '\0';

    return (dest);
}
