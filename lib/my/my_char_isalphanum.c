/*
** EPITECH PROJECT, 2019
** is alpha num
** File description:
** sdf
*/

#include "my.h"

int my_char_isalphanum(char c)
{
    if (my_char_isnum(c) || my_char_isalpha(c))
        return (1);
    return (0);
}
