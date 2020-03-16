/*
** EPITECH PROJECT, 2019
** QS
** File description:
** JJJH
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1 , &c, 1);
    return (1);
}
