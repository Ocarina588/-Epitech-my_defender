/*
** EPITECH PROJECT, 2019
** function three
** File description:
** sdf
*/

#include "my.h"

void print_bool(char *bool, char *flags, int *counter)
{
    for (int i = 0; i < 5 ; i++) {
        if (bool[i])
            *counter += my_putchar(flags[i]);
        if (bool[i] && (i == 1 || i == 3) && i++);
    }
}

int check_is_good_number(char *str, int i, char *flags)
{
    int j = 0;
    while (str[i + j])
    {
        if ((str[i + j] > '9' || str[i + j] < '0')
            && get_index(str[i + j], flags) != -1)
            return (j);
        if ((str[i + j] > '9' || str[i + j] < '0')
            && get_index(str[i + j], flags) == -1)
            return (0);
        j++;
    }
    return (0);
}

int is_num(char c)
{
    if (c <= '9' && c > '0')
        return (1);
    return (0);
}

void move_index(char *str, int *i)
{
    char flag[] = "SscdiouxXpb%";
    char fl_t[] = "#+ -0";

    for (*i; str[*i] ; (*i)++)
        if (get_index(str[*i], flag) != -1)
            return;
}

void move_index_bad(char *str, int *i)
{
    char flag[] = "SscdiouxXpb%";
    char fl_t[] = "#+ -0";

    for (*i; str[*i] ; (*i)++)
        if ((get_index(str[*i], flag) == -1 && get_index(str[*i], fl_t) == -1))
            return;

}