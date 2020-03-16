/*
** EPITECH PROJECT, 2019
** trncat
** File description:
** sdkjf
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int len = my_strlen(dest);
    int i;

    for ( i = 0 ; i < nb && src[i] != '\0' ; i++)
        dest[len + i] = src[i];

    dest[len + i] = '\0';

    return (dest);
}
