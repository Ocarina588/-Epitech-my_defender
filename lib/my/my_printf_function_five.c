/*
** EPITECH PROJECT, 2019
** function five
** File description:
** sdf
*/

#include "my.h"

int print_xm_flags(unsigned int nb, int nb_spaces, flags_t info)
{
    int total = 0;

    if (info.tab[3]) {
        my_putstr("0X");
        total += my_putnbr_base_unsigned(nb, 16, 1);
        total += print_spaces(nb_spaces, info.tab[4]);
    } else {
        if (info.tab[4]) {
            my_putstr("0X");
            total += print_spaces(nb_spaces, info.tab[4]);
            total += my_putnbr_base_unsigned(nb, 16, 1);
        } else {
            total += print_spaces(nb_spaces, info.tab[4]);
            my_putstr("0X");
            total += my_putnbr_base_unsigned(nb, 16, 1);
        }
    }
    return (total + 2);
}

int print_x_flags(unsigned int nb, int nb_spaces, flags_t info)
{
    int total = 0;

    if (info.tab[3]) {
        my_putstr("0x");
        total += my_putnbr_base_lowercase(nb, 16, 1);
        total += print_spaces(nb_spaces, info.tab[4]);
    } else {
        if (info.tab[4]) {
            my_putstr("0x");
            total += print_spaces(nb_spaces, info.tab[4]);
            total += my_putnbr_base_lowercase(nb, 16, 1);
        } else {
            total += print_spaces(nb_spaces, info.tab[4]);
            my_putstr("0x");
            total += my_putnbr_base_lowercase(nb, 16, 1);
        }
    }
    return (total + 2);
}

int print_p_flags_r(long int nb, int nb_spaces, flags_t info)
{
    int total = 0;

    if (info.tab[1] || info.tab[2])
        nb_spaces--;
    if (info.tab[1])
        total += my_putchar('+');
    if (info.tab[2])
        total += my_putchar(' ');
    my_putstr("0x");
    total += my_putnbr_memory(nb, 1);
    total += print_spaces(nb_spaces, info.tab[4]);

    return (total);
}

int print_p_flags_l(long int nb, int nb_spaces, flags_t info, int total)
{
    if (info.tab[1] || info.tab[2])
        nb_spaces--;
    if (info.tab[4]) {
        if (info.tab[1])
            total += my_putchar('+');
        if (info.tab[2])
            total += my_putchar(' ');
        my_putstr("0x");
        total += print_spaces(nb_spaces, info.tab[4]);
        total += my_putnbr_memory(nb, 1);
    } else {
        total += print_spaces(nb_spaces, info.tab[4]);
        if (info.tab[1])
            total += my_putchar('+');
        if (info.tab[2])
            total += my_putchar(' ');
        my_putstr("0x");
        total += my_putnbr_memory(nb, 1);
    }
    return (total);
}