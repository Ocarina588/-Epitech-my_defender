/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** task 04 day 03
*/

#include "my.h"

int    my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
        return (0);
    }
    else {
        my_putchar('N');
        return (1);
    }
}
