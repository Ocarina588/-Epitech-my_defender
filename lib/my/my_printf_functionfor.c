/*
** EPITECH PROJECT, 2019
** function for
** File description:
** sdf
*/

#include "my.h"

int print_s_null(flags_t info)
{
    int total = 0;
    if (info.tab[3]) {
        my_putstr("(null)");
        total += print_spaces(info.tab[5] - 6, 0);
    } else {
        total += print_spaces(info.tab[5] - 6, 0);
        my_putstr("(null)");
    }

    return (6 + total);
}

int my_strlen_nonprintable(char *str)
{
    int total = 0;
    if (!str)
        return (0);
    for (int i = 0; str[i] != '\0' ; i++)
        if (str[i] < 32 || str[i] >= 127)
            total += 4;
        else
            total += 1;
    return (total);
}

int print_nonprintable_str(char *str)
{
    int total = 0;
    for (int i = 0; str[i] != '\0' ; i++)
        if (str[i] < 32 || str[i] >= 127) {
            print_nonprintable(str[i]);
            total += 4;
        }
        else {
            print("%c", str[i]);
            total += 1;
        }
    return (total);
}

int print_d_flags(int nb, int nb_spaces, flags_t info, int total)
{
    if (info.tab[3]) {
        if (info.tab[2] && nb > 0)
                total += my_putchar(' ');
        if (info.tab[1] && nb > 0)
                total += my_putchar('+');
            total += my_putnbr_base(nb, 10, 1);
            total += print_spaces(nb_spaces, info.tab[4]);
    } else {
        if (info.tab[4] )
            total += print_d_flags_zero(nb, nb_spaces, info);
        else {
            total += print_spaces(nb_spaces, info.tab[4]);
            if (info.tab[2] && nb > 0)
                total += my_putchar(' ');
            if (info.tab[1] && nb > 0)
                total += my_putchar('+');
            total += my_putnbr_base(nb, 10, 1);
        }
    }
    return (total);
}

int print_d_flags_zero(int nb, int nb_spaces, flags_t info)
{
    int total = 0;

    if (info.tab[1])
        total += my_putchar('+');
    if (info.tab[2])
        total += my_putchar(' ');
    total += print_spaces(nb_spaces, info.tab[4]);
    total += my_putnbr_base(nb, 10, 1);

    return (total);
}