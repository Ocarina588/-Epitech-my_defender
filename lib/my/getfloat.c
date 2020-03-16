/*
** EPITECH PROJECT, 2019
** getfloat
** File description:
** sdf
*/

#include "my.h"

int nb_len(int nb)
{
    int tmp = nb;
    int len = 0;

    while (tmp) {
        tmp /= 10;
        len++;
    }
    return (nb ? len : 1);
}

char *nbstr(int nb)
{
    char one[32];
    static char two[10];
    int tmp = nb;

    for (int i = 0; i < nb_len(nb) ; i++) {
        one[i] = tmp % 10;
        tmp /= 10;
    }
    for (int i = 0, j = nb_len(nb) - 1; i < nb_len(nb) ; i++, j--)
        two[i] = one[j] + '0';
    two[nb_len(nb)] = 0;
    return (two);
}

double getdouble(char *str)
{
    double result = 0;
    int first = my_getnbr(str);
    int second = 0;
    int rep_sign = 1;
    for (int i = 0; str[i] ; i++) {
        if ((str[i] == '-' || str[i] == '+') && !rep_sign)
            break;
        if (str[i] >= '0' && str[i] <= '9')
            rep_sign = 0;
        if (str[i] == ' ')
            break;
        if (str[i] == '.' && (str[i + 1] <= '9' && str[i + 1] >= '0')) {
            second = my_getnbr(str + i + 1);
            break;
        }
    }
    if (first < 0)
        second *= -1;
    result = first + (double)second / my_compute_power_rec(10, nb_len(second));
    return (result);
}