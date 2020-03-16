/*
** EPITECH PROJECT, 2019
** flags function
** File description:
** sdf
*/

#include "my.h"

int check_is_good_flag(char *str, int *counter)
{
    char fl[] = "SscdiouxXpb%";
    char fl_s[] = "#+ -0";
    char bool[5] = {0};
    int i;

    for (i = 0; str[i] ; i++) {
        if (is_num(str[i]) && check_is_good_number(str, i, fl))
            return (get_index(str[i + check_is_good_number(str, i, fl)], fl));
        if (get_index(str[i], fl) == -1 && get_index(str[i], fl_s) == -1) {
            *counter += my_putchar('%');
            break;
        }
        if (get_index(str[i], fl_s) != -1)
            bool[get_index(str[i], fl_s)] = 1;
        if (get_index(str[i], fl) != -1)
            return (get_index(str[i], fl));
    }
    print_bool(bool, fl_s, counter);
    *counter += my_putchar(str[i]);
    return (-1);
}

flags_t init_flags(char *str)
{
    flags_t flags;
    char info[] = "#+ -0";
    for (int i = 0; i < 6 ; i++)
        flags.tab[i] = 0;
    for (int i = 0; get_index(str[i], "SscdiouxXpb%") == -1 ; i++) {
        if (get_index(str[i], info) != -1)
            flags.tab[get_index(str[i], info)] = 1;
        if (is_num(str[i])) {
            flags.tab[5] = my_getnbr(str + i);
            break;
        }
    }
    if (flags.tab[1])
        flags.tab[2] = 0;
    if (flags.tab[3])
        flags.tab[4] = 0;
    return (flags);
}