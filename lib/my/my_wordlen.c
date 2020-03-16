/*
** EPITECH PROJECT, 2019
** world len
** File description:
** sdf
*/

#include "my.h"

int my_wordlen(char const *str, int i)
{
    int len = 0;

    for (i = i ; my_char_isalphanum(str[i]) ; i++)
        len++;

    return (len);
}
