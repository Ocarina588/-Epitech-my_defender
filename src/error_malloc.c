/*
** EPITECH PROJECT, 2020
** error malloc
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"

int error_manager(int val, int mode)
{
    static int fd = 0;

    if (mode == set)
        fd = val;
    return (fd);
}

void send_error(void)
{
    error_manager(1, set);
}

int check_error(void)
{
    return (error_manager(0, get));
}