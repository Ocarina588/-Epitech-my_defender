/*
** EPITECH PROJECT, 2019
** my put nbr base
** File description:
** sdf
*/

#include "my.h"

int print_spaces(int nb, int rep)
{
    char c = (rep) ? '0' : ' ';
    int i = 0;

    if (nb > 0)
        for ( i ; i < nb; i++)
            my_putchar(c);

    return (i);
}

int my_putnbr_base(int n, int base, int rep)
{
    int total = 0;
    char lo[] = "0123456789ABCDEF";
    if ( n == -2147483648 ){
        total += my_putchar('-');
        total += my_putnbr_base(2147, base, rep);
        total += my_putnbr_base(483648, base, rep);
        return (total);
    }
    if (n < 0) {
        total += (rep) ? (my_putchar('-')) : (1);
        n *= -1;
    }
    if ( n >= base ){
        total += my_putnbr_base( n / base , base, rep);
        my_putnbr_base( n % base , base, rep);
    }
    else if (rep)
            my_putchar(lo[n]);
    return (total + 1);
}

int my_putnbr_base_unsigned(unsigned int n, int base, int rep)
{
    char lo[] = "0123456789ABCDEF";
    int total = 0;
    if ( n >= base ){
        total += my_putnbr_base( n / base , base, rep);
        my_putnbr_base( n % base , base, rep);
    }
    else if (rep)
        my_putchar(lo[n]);
    return (total + 1);
}

int my_putnbr_base_lowercase(unsigned int n, int base, int rep)
{
    char lo[] = "0123456789abcdef";
    int total = 0;
    if ( n >= base ){
        total += my_putnbr_base_lowercase( n / base , base, rep);
        my_putnbr_base_lowercase( n % base , base, rep);
    }
    else if (rep)
        my_putchar(lo[n]);
    return (total + 1);
}

int my_putnbr_memory(long int n, int rep)
{
    char lo[] = "0123456789abcdef";
    int total = 0;
    if ( n >= 16 ){
        total += my_putnbr_memory(n / 16, rep);
        my_putnbr_memory(n % 16, rep);
    }
    else if (rep)
        my_putchar(lo[n]);
    return (total + 1);
}