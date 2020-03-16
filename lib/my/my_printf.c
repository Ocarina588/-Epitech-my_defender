/*
** EPITECH PROJECT, 2019
** function
** File description:
** sdf
*/

#include <stdarg.h>
#include <unistd.h>
#include "my.h"

int print_nonprintable(char c)
{
    int ten = 64;
    print("\\");
    for (int i = 0 ; i < 2 ; i++) {
        print("%d", c / ten);
        c = c - (c / ten) * ten;
        ten = 8;
    }
    print("%d", c);
    return (4);
}

int get_index(char c, char *str)
{
    for (int i = 0; str[i] != '\0' ; i++)
        if (str[i] == c)
            return (i);
    return (-1);
}

int print_per(va_list va, char *str)
{
    return (my_putchar('%'));
}

int type_manager(char *str, va_list va)
{
    int total = 0;
    int *trash;
    int (*functions[])(va_list, char *) =
        {print_sbig, print_s, print_c, print_d, print_d, print_o, print_u,
        print_x, print_xm, print_p, print_b, print_per};

    return (functions[check_is_good_flag(str, trash)](va, str));
}

int print(char *str, ...)
{
    int index;
    va_list va;
    va_start(va, str);
    int count_total = 0;
    int i = 0;

    for ( i = 0; str && str[i] ; i++) {
        if (str[i] == '%') {
            i++;
            index = check_is_good_flag(str + i, &count_total);
            (index != -1) ? (count_total += type_manager(str + i, va)) : 0;
            (index != -1) ? (move_index(str, &i)) : (move_index_bad(str, &i));
        }
        else {
            write(1, &str[i], 1);
            count_total++;
        }
    }
    va_end(va);
    return (count_total);
}