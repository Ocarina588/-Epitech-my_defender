/*
** EPITECH PROJECT, 2019
** task 02 day 04
** File description:
** cc
*/

#include "my.h"

int    my_putstr(const char *str)
{
    int i = 0;

    while ( *(str + i) != '\0' )
    {
        my_putchar( *(str + i) );
        i++;
    }

    return (i);
}
