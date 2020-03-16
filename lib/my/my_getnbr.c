/*
** EPITECH PROJECT, 2019
** task 05 day 04
** File description:
** cc
*/

#include "my.h"

int check_good(char const *str)
{
    int i = 0;
    while (1)
    {
        if ( *(str + i) >= '0' && *(str + i) <= '9' )
            return (1);

        if ( *(str + i) != '-' && *(str + i) != '+' )
            return (0);

        if ( *(str + i) == '\0' )
            return (0);
        i++;
    }
}

int    give_operator(char const *str)
{
    int operator = 0;
    int i = 0;

    while (1)
    {
        if ( *(str + i) == '-' )
            operator++;

        if ( *(str + i) <= '9' && *(str + i) >= '0' )
            return (operator % 2);
        i++;
    }
}

int    is_number(char c)
{
    if ( c >= '0' && c <= '9' )
        return (1);

    return (0);
}

int end_retur(char const *str, int nmb)
{
    if ( give_operator(str) )
        nmb *= -1;

    if ( !check_good(str) )
        return (0);

    if ((!give_operator(str) && nmb < 0) || (give_operator(str) && nmb >= 0))
        return (0);

    return (nmb);
}

int    my_getnbr(char const *str)
{
    int i = 0;
    int size = 0;
    int nmb = 0;
    int rep = 0;

    while (str[i] > '9' || str[i] <= '0') {
        if (str[i] == '0')
            rep = 1;
        if (str[i] == '\0' || (!my_char_isnum(str[i++]) && rep))
            return (0);
    }
    while (is_number(str[i])){
        nmb = nmb * 10 + ( str[i++] - '0' );
        size++;
    }
    if ( size > 10 )
        return (0);

    return (end_retur(str, nmb));
}
