/*
** EPITECH PROJECT, 2019
** function for my_printf
** File description:
** sdf
*/
#include <stdarg.h>
#include <stdio.h>
#include "my.h"

int print_d(va_list va, char *str)
{
    int nb = va_arg(va, int);
    flags_t info = init_flags(str);
    int nb_spaces =  info.tab[5] - my_putnbr_base(nb, 10, 0);
    int total = 0;

    if ((info.tab[2] || info.tab[1]) && nb > 0) {
        nb_spaces--;
        total += print_d_flags(nb, nb_spaces, info, 0);
        return (total);
    }

    if (info.tab[3]) {
        total += my_putnbr_base(nb, 10, 1);
        total += print_spaces(nb_spaces, info.tab[4]);
    } else {
        total += print_spaces(nb_spaces, info.tab[4]);
        total += my_putnbr_base(nb, 10, 1);
    }

    return (total);
}

int print_c(va_list va, char *str)
{
    char c = (char)va_arg(va, int);
    flags_t info = init_flags(str);
    int nb_spaces = info.tab[5] - 1;
    int total = 0;

    if (info.tab[3]) {
        my_putchar(c);
        total += print_spaces(nb_spaces, 0);
    } else {
        total += print_spaces(nb_spaces, 0);
        my_putchar(c);
    }
    return (1 + total);
}

int print_s(va_list va, char *s)
{
    char *str = va_arg(va, char *);
    flags_t info = init_flags(s);
    int nb_spaces = info.tab[5] - my_strlen(str);
    int total = 0;

    if (!str)
        return (print_s_null(info));

    if (info.tab[3]) {
        my_putstr(str);
        total += print_spaces(nb_spaces, 0);
    } else {
        total += print_spaces(nb_spaces, 0);
        my_putstr(str);
    }

    return (my_strlen(str) + total);
}

int print_o(va_list va, char *str)
{
    unsigned int nb = va_arg(va, unsigned int);
    flags_t info = init_flags(str);
    int nb_spaces =  info.tab[5] - my_putnbr_base_unsigned(nb, 8, 0);
    int total = 0;

    if (info.tab[0])
        nb_spaces--;

    if (info.tab[3]) {
        if (info.tab[0])
            total += my_putchar('0');
        total += my_putnbr_base_unsigned(nb, 8, 1);
        total += print_spaces(nb_spaces, info.tab[4]);
    } else {
        total += print_spaces(nb_spaces, info.tab[4]);
        if (info.tab[0])
            total += my_putchar('0');
        total += my_putnbr_base_unsigned(nb, 8, 1);
    }
    return (total);
}

int print_u(va_list va, char *str)
{
    unsigned int nb = va_arg(va, unsigned int);
    flags_t info = init_flags(str);
    int nb_spaces =  info.tab[5] - my_putnbr_base_unsigned(nb, 10, 0);
    int total = 0;

    if (info.tab[3]) {
        total += my_putnbr_base_unsigned(nb, 10, 1);
        total += print_spaces(nb_spaces, info.tab[4]);
    } else {
        total += print_spaces(nb_spaces, info.tab[4]);
        total += my_putnbr_base_unsigned(nb, 10, 1);
    }

    return (total);
}