/*
** EPITECH PROJECT, 2020
** tower menu func
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"
#include "button.h"

void choose_poison(void *arg, ...)
{
    gg()->scene[1].plug.type = poison;
}

void choose_sniper(void *arg, ...)
{
    gg()->scene[1].plug.type = sniper;
}

void choose_basic(void *arg, ...)
{
    gg()->scene[1].plug.type = basic;
}

void choose_trap(void *arg, ...)
{
    gg()->scene[1].plug.type = trap;
}