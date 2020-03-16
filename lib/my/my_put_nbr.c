/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** task 7 day 04
*/

#include "my.h"

int my_put_nbr(int n)
{
    int  total = 0;
    if ( n == -2147483648 ){
        total += my_putchar('-');
        total += my_put_nbr(2147);
        total += my_put_nbr(483648);
        return (total);
    }
    if (n < 0) {
        total += my_putchar('-');
        n *= -1;
    }
    if ( n >= 10 ){
        total += my_put_nbr( n / 10 );
        my_put_nbr( n % 10 );
    }
    else
        my_putchar( n + 48 );
    return (total + 1);
}
