/*
** EPITECH PROJECT, 2019
** function
** File description:
** sdf
*/

#include "my.h"

int print_xm(va_list va, char *str)
{
    int nb = va_arg(va, unsigned int);
    flags_t info = init_flags(str);
    int nb_spaces = info.tab[5] - my_putnbr_base_unsigned(nb, 16, 0);
    int total = 0;

    if (info.tab[0]) {
        nb_spaces -= 2;
        total += print_xm_flags(nb, nb_spaces, info);
        return (total);
    }
    if (info.tab[3]) {
        total += my_putnbr_base_unsigned(nb, 16, 1);
        total += print_spaces(nb_spaces, info.tab[4]);
    } else {
        total += print_spaces(nb_spaces, info.tab[4]);
        total += my_putnbr_base_unsigned(nb, 16, 1);
        }

    return (total);
}

int print_x(va_list va, char *str)
{
    int nb = va_arg(va, unsigned int);
    flags_t info = init_flags(str);
    int nb_spaces = info.tab[5] - my_putnbr_base_lowercase(nb, 16, 0);
    int total = 0;

    if (info.tab[0]) {
        nb_spaces -= 2;
        total += print_x_flags(nb, nb_spaces, info);
        return (total);
    }
    if (info.tab[3]) {
        total += my_putnbr_base_lowercase(nb, 16, 1);
        total += print_spaces(nb_spaces, info.tab[4]);
    } else {
        total += print_spaces(nb_spaces, info.tab[4]);
        total += my_putnbr_base_lowercase(nb, 16, 1);
        }

    return (total);
}

int print_p(va_list va, char *str)
{
    long int nb = va_arg(va, long int);
    flags_t info = init_flags(str);
    int nb_spaces = info.tab[5] - (my_putnbr_memory(nb, 0) + 2);
    int total = 0;
    if (info.tab[3])
        total += print_p_flags_r(nb, nb_spaces, info);
    else
        total += print_p_flags_l(nb, nb_spaces, info, 0);

    return (total + 2);
}

int print_b(va_list va, char *str)
{
    unsigned int nb = va_arg(va, unsigned int);
    flags_t info = init_flags(str);
    int nb_spaces =  info.tab[5] - my_putnbr_base_unsigned(nb, 2, 0);
    int total = 0;

    if (info.tab[3]) {
        total += my_putnbr_base_unsigned(nb, 2, 1);
        total += print_spaces(nb_spaces, info.tab[4]);
    } else {
        total += print_spaces(nb_spaces, info.tab[4]);
        total += my_putnbr_base_unsigned(nb, 2, 1);
    }
    return (total);
}

int print_sbig(va_list va, char *s)
{
    char *str = va_arg(va, char *);
    flags_t info = init_flags(s);
    int nb_spaces = info.tab[5] - my_strlen_nonprintable(str);
    int total = 0;

    if (!str) {
        total += print_s_null(info);
        return (total);
    }
    if (info.tab[3]) {
        total += print_nonprintable_str(str);
        total += print_spaces(nb_spaces, 0);
    } else {
        total += print_spaces(nb_spaces, 0);
        total += print_nonprintable_str(str);
    }

    return (total);
}